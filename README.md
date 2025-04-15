# 42-push_swap
**Based on:** [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) and [push_swap TUTORIAL!](https://www.youtube.com/watch?v=wRvipSG4Mmk&t=896s)

This GitHub project implements the Mechanical Turk algorithm to efficiently solve the 42-push_swap project. It optimally moves elements between two stacks (A and B) to achieve a sorted sequence using minimal operations.

This repository is intended to help other 42 students by giving them the tools to understand the "Mechanical Turk" algorithm in a visual way, explaining how it works step by step.

## Usage

After cloning the repository, you can execute the following commands in your terminal:

- **`make all`**: Compiles project and generates push_swap.exe file

- **`make clean`**: Clean all  object files generated after doing make all

- **`make fclean`**: Erase object files by executing make clean, as well as the compiled .exe program

- **`make re`**: Executes the `fclean` command, followed by the `all` command to update compiled .exe file after doing changes in any .c file. 

For testing and learning purposes, there are two functions in the ft_utils.c file that can be used to display the state of both, a and b stacks, at any moment during the execution of the code.

## The algorithm

For this project, I used the Mechanical Turk algorithm, created by former 42 student [Ali Ogun](https://github.com/ayogun). While this isn't a standard sorting algorithm like quicksort or radix sort, it's ideal for achieving the maximum score in the 42-push_swap project due to its specific constraints.

### Allowed moves

<img src="https://i.imgur.com/pLYP3EO.gif" alt="SA move">
<img src="https://i.imgur.com/Wq6cqEL.gif" alt="SB move">
<img src="https://i.imgur.com/f7RG2fr.gif" alt="SS move">
<img src="https://i.imgur.com/ZpBikjD.gif" alt="PA move">
<img src="https://i.imgur.com/7sjmAFB.gif" alt="PB move">
<img src="https://i.imgur.com/INjPyFk.gif" alt="RA move">
<img src="https://i.imgur.com/NAbNEKj.gif" alt="RB move">
<img src="https://i.imgur.com/raXPPmR.gif" alt="RR move">
<img src="https://i.imgur.com/1i9vFuH.gif" alt="RRA move">
<img src="https://i.imgur.com/Yy67poL.gif" alt="RRB move">
<img src="https://i.imgur.com/PMJ6re5.gif" alt="RRR move">

### Core idea

To better visualize how the algorithm works, think of each stack as a circular rotating element

<img src="https://i.imgur.com/wCSC1IG.gif" alt="Stack as a rotating element/list">

Basically, what the algorithm does is to rotate stack b so that the incomming number from a is placed in b in **descencing** order, until stack a has only three elements left. Afterwards, stack a orders the remaining three elements in **ascending** order, to finally push each b element in its corresponding position.

<img src="https://i.imgur.com/iXyLX7l.gif" alt="Visual example of the Mechanical Turk algorithm">

This is a good approach, but we can refine it by identifying which number requires the fewest moves to transfer from stack a to stack b. Let's see how this works step by step.

### Previous notes:

If there is only one node in a, don't do nothing

If there is only two nodes in a, check if they are sorted. If they aren't, just do sa

If only three nodes in a, order them in a without pushing any node to b (try to create your own ordering algorithm for three nodes!).

If you think you can create an optimized algorithm for 5 elements, go for it, but the Mechanical Turk algorithm can be applied starting at four elements.

## Steps for the Mechanical Turk algorithm:

### Step 1:

Push the first two nodes from stack a to stack b. For a stack of only four nodes in a, push just one node to b.

<img src="https://i.imgur.com/HzOBILp.gif" alt="Mechanical Turk algorithm - step 1">

From this point on, we'll continue pushing nodes from stack a to stack b until only three nodes remain in a. Before each move, we need to calculate which node in stack a requires the fewest moves to push to b (the lowest push cost). To determine this, follow these steps **before each push from a-stack to b-stack:**

### Step 2:

Calculate the target node for each a-node in b-stack: find the closest smaller value to each a-node. If there's no smaller number in b, use the largest value. This target node must be on top of stack b so that when we push an a-node to b-stack, it maintains the correct **descending order**.

<img src="https://i.imgur.com/V7Vlpwh.gif" alt="Mechanical Turk algorithm - step 2">

Next, we need to find which node in a-stack is cheapest to move to b-stack. This means calculating the total number of operations needed to bring both the a-node and its target node to the tops of their respective stacks.

### Step 3:

Index each element in both stacks. This helps determine if both the a-node and its b-target node are above or below the median. When both nodes are on the same side of their respective medians, you can use rr or rrr (one move) instead of ra and rb or rra and rrb (two moves), saving an operation.

<img src="https://i.imgur.com/AnC01r0.gif" alt="Mechanical Turk algorithm - step 3">

IMPORTANT: For stacks with an odd number of elements, nodes are considered "above the median" from the central node (in this case 18) up to the top of the stack.

### Step 4:

Calculate the push cost for each node in stack A: count the total moves needed to position both the node and its target at the top of their respective stacks, plus the final push to stack B.

<img src="https://i.imgur.com/GtENulK.gif" alt="Mechanical Turk algorithm - step 4">

- 80: rrb → pb = 2 moves
- -1: ra → rrb → pb = 3 moves
- 18: ra → ra → pb = 3 moves
- -70: rrr → ra → pb = 3 moves
- -61: rrr → pb = 2 moves

IMPORTANT: Check if both nodes (A-node and its target) are above or below the median—this allows you to save moves by using rr or rrr operations.

### Step 5:

Identify the cheapest node.

<img src="https://i.imgur.com/caHIHsw.gif" alt="Mechanical Turk algorithm - step 5">

NOTE: If there are two nodes with the cheapest value, select the first one found.

### Step 6:

<img src="https://i.imgur.com/akDJBS5.gif" alt="Mechanical Turk algorithm - step 6">

Push the cheapest node from a-stack to b-stack.

### Step 7:

Repeat steps **2 to 6** until only **three elements** remain in the **a-stack**.

<img src="https://i.imgur.com/67IQo6v.gif" alt="Mechanical Turk algorithm - step 7">

By the end of this step, all elements in the **b-stack** will be sorted in descending order.

### Step 8:

Sort the remaining three elements in the **a-stack** in ascending order.

<img src="https://i.imgur.com/j6d7pEy.gif" alt="Mechanical Turk algorithm - step 8">

Now, we need to push all elements from the **b-stack** back into the **a-stack** until **b** is empty following these steps:

### Step 9:

Assign an **index** to each node in both stacks.

<img src="https://i.imgur.com/imrY6tj.gif" alt="Mechanical Turk algorithm - step 9">

### Step 10:

For the **top node of b**, determine its **target node** in **a**—the closest **larger** value in the **a-stack**. If no larger value exists, the target is the smallest value in a.

<img src="https://i.imgur.com/HBt3JgO.gif" alt="Mechanical Turk algorithm - step 10">

NOTE:  Check whether the **target node** in **a** is **above or below the median** to decide whether ra or rra is the most efficient move.

### Step 11:

Move the **target node** to the top of **a** and push the **top node of b** into **a**.

<img src="https://i.imgur.com/kRex4J5.gif" alt="Mechanical Turk algorithm - step 11">

- rra -> pa

### Step 12:

Repeat **steps 9 to 11** until **b-stack** is empty.

<img src="https://i.imgur.com/9O0Ser5.gif" alt="Mechanical Turk algorithm - step 12">

### Step 13:

Rotate **a-stack** until its **smallest value** is at the top.

<img src="https://i.imgur.com/aZTI5rH.gif" alt="Mechanical Turk algorithm - step 13">

NOTE: Consider if the lowest value is above or below the median to decide if ra or rra is the optimal move.

🎉 **Congratulations!** Your stack is now sorted! 🚀

## Possible Optimizations

While working on this guide, I noticed a few potential optimizations that could improve efficiency:

1. **Step 9 Optimization**:
    - It may not be necessary to index **all nodes in b** during step 9. I included it because my code does this, but I haven't tested it without indexing. You might want to check if it's actually needed.
2. **Step 10 Optimization**:
    - When pushing nodes from **a to b**, my code calculates the **push cost** for all nodes in **a**. However, if you find a node with a **push cost of 1**, you can **stop the calculation** early since **1 is the minimum possible cost**, making further checks unnecessary.

## Author
<br>
<a href="https://www.linkedin.com/in/eg-delacruz/" target="_blank">
<img src="https://media.licdn.com/dms/image/v2/D4D03AQGSBV1mzrlVFQ/profile-displayphoto-shrink_800_800/profile-displayphoto-shrink_800_800/0/1731940599224?e=1742428800&v=beta&t=3igUnVuGAMvdVgAU_Lbz8AjtgPSQF4rFk2GviR_VXIg" alt="Gerardo De La Cruz" width="200"/>
  <p>Gerardo De La Cruz</p>
</a>
<br>
<br>
<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTVInHuUPtp3uiEuvF0aYAkFBUzpnr65b2CDA&s" alt="42 Madrid Logo"/>

If you liked the repository, don't forget to give it a ⭐
