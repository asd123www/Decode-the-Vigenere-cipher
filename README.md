# Decode-the-Vigenere-cipher

The algorithm is simple.

First, based on the design of Vigenere-cipher, we enumerate the possible key length n.

Then obviously the sequence of i, i+n, i+2n, ... is reducted to the caesar code, which can be decoded by the frequency of the alphabet.

Measure the distance between possible distribution and the ground truth, then combine n sequences with the topk.

Dfs is implemented for combination of the topk.
