## My Thoughts (Wrong)
1. First sort the array based on the first element.
2. Assume there are k distinct first element, thus we will have at most k max envelopes.
3. Among elements that have same first element, we try to choose the smallest element.

## Solution
1. Sort mainly based on the first element and based on second element inversely only if the first elements are the same
2. Then the remaining job is to find longest increasing subsequence.
3. Here is a trick to make this process nlogn
    1. First we maintain a dp array to hold this increasing subsequence
    2. For all the element from the envelopes, we use "lower_bound" to find the first iterator that is greater than current envelope's second field.
    3. If that iterator is dp.end(), that means this is a larger envelope (we sorted it). We add it to our dp.
    4. If that iterator is in the midle of dp, replace that iterator value with current envelope's second filed.

## Explanation for 3.3 - 3.4 (assume second field represents height)
1. We now have i LIS.  
For any i+1 th envelope, if no element from dp has larger value than i+1 th evelope's height. We add it, It satisties LIS configuration.  
If you find i+1 th envelope having smaller height than some of dp. You just swap with the lower bound iterator. If that i+1 th envelope doesn't consitute a LIS, it's no harm to do this swap, because we won't introduce any new envolope. (We only make this dp array as "small" as possible)

## Explanation why we sort e1[1] > e2[1] when e1[0] == e2[0].

Because your goal is to convert it to a longest subsequence problem. If envelopes have same width, they cannot be ruassian doll together, you sort the second field inversely to maintain this properties.
