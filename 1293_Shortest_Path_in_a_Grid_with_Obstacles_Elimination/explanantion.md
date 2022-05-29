## Idea
1. Base idea is BFS (oen way to find shortest path)
2. Use a 2D vector to store visiting information. (Remember the number of remaining clearing times.)
    - If your current available time is greater than recorded one, add that move into queue
    - Otherwise, don't add
