class Robot {

    int x, y;
    int width, height;
    int dir; // 0=East, 1=North, 2=West, 3=South

    int[][] dirs = {
        {1, 0},   // East
        {0, 1},   // North
        {-1, 0},  // West
        {0, -1}   // South
    };

    String[] dirNames = {"East", "North", "West", "South"};

    int perimeter;

    public Robot(int width, int height) {
        this.width = width;
        this.height = height;
        this.x = 0;
        this.y = 0;
        this.dir = 0;
        this.perimeter = 2 * (width + height) - 4;
    }

    public void step(int num) {
        num %= perimeter;

        // Special case: full cycle
        if (num == 0) {
            if (x == 0 && y == 0) {
                dir = 3; // South
            }
            return;
        }

        while (num > 0) {
            int nx = x + dirs[dir][0];
            int ny = y + dirs[dir][1];

            // Check boundary
            if (nx < 0 || ny < 0 || nx >= width || ny >= height) {
                dir = (dir + 1) % 4; // turn CCW
            } else {
                x = nx;
                y = ny;
                num--;
            }
        }
    }

    public int[] getPos() {
        return new int[]{x, y};
    }

    public String getDir() {
        return dirNames[dir];
    }
}