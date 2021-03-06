# 02-push_swap
An algorithm project using two stacks.

push_swap takes a list of numbers as an argument and sorts the list using the fewest instructions possible. Two stacks ("a" and "b") and the following instructions are avaliable:

- **sa : swap a** - swap the first 2 elements at the top of stack a.
- **sb : swap b** - swap the first 2 elements at the top of stack b.
- **ss : sa** and **sb** at the same time.
- **pa : push a** - take the first element at the top ofb and put it at the top of a.
- **pb : push b** - take the first element at the top of a and put it at the top of b.
- **ra : rotate a** - shift up all elements of stack a by 1. The first element becomesthe last one.
- **rb : rotate b** - shift up all elements of stack b by 1. The first element becomes the last one.
- **rr : ra** and **rb** at the same time.
- **rra : reverse rotate a** - shift down all elements of stack a by 1. The last element becomes the first one.
- **rrb : reverse rotate b** -  shift down all elements of stack b by 1. The last element becomes the first one.
- **rrr : rra** and **rrb** at the same time.

![example](../assets/push_swap-example.png)

![screenshot](../assets/push_swap-screenshot.png)
