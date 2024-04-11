# stableMarriage
The goal of this project to match n men and n women with their preference
rankings of each other and give a "stable" set of marriages. This project
uses backtracking to find its solutions.
What is a "Stable" matching
A matching is stable if there are no “instabilities.” Say the match assigns m1
to w1 and m2 to w2.
An instability is the situation where there is a mutual greater preference
for the other person’s partner than for one’s own.
For example, m1 would prefer w2 to w1 and likewise w2 prefers m1 to m2.
c -> man c (passed to ok function)
i -> man i (from i in the for loop)
q[c] -> wife of man c
q[i] -> wife of man i
