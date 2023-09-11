class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
    }
};

/*
We have n characters and we are going to insert 4 l inside.
We can add them in the front, in the middle or in the end.
How many ways do we have?
1st l, we have n+1 position to insert.
2nd l, we have n+2 position to insert.
3rd l, we have n+3 position to insert.
4th l, we have n+4 position to insert.
Also 4 l are the same,
there are (n + 1) * (n + 2) * (n + 3) * (n + 4) / 4! ways.

The character before the 1st l, we set to a.
The character before the 2nd l, we set to e.
The character before the 3rd l, we set to i.
The character before the 4th l, we set to o.
The character before the 5th l, we set to u.
*/
