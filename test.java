import java.util.*;

class Main {
    static final int NO_PARENT = -1;
    static Set<Integer> edges = new LinkedHashSet<>();
    static Set<Integer> dists = new TreeSet<>();

    static void shortestPath(int[][] adjacencyMatrix, int src, int dest) {
        int n = adjacencyMatrix[0].length;
        int[] shortest = new int[n];
        boolean[] added = new boolean[n];
        for (int v = 0; v < n; v++) {
            shortest[v] = Integer.MAX_VALUE;
            added[v] = false;
        }
        shortest[src] = 0;
        int[] parents = new int[n];
        parents[src] = NO_PARENT;

        for (int i = 1; i < n; i++) {
            int v1 = 0;
            int min = Integer.MAX_VALUE;
            for (int v = 0; v < n; v++) {
                if (!added[v] && shortest[v] < min) {
                    v1 = v;
                    min = shortest[v];
                }
            }
            added[v1] = true;
            for (int v = 0; v < n; v++) {
                int dist = adjacencyMatrix[v1][v];
                if (dist > 0 && ((min + dist) < shortest[v])) {
                    parents[v] = v1;
                    shortest[v] = min + dist;
                }
            }
        }
        dists.add(shortest[dest]);
        visitUtil(dest, parents);
    }

    static void visitUtil(int i, int[] parents) {
        if (i == NO_PARENT)
            return;

        visitUtil(parents[i], parents);
        edges.add(i);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N, M, T, C;
        N = in.nextInt();
        M = in.nextInt();
        T = in.nextInt();
        C = in.nextInt();

        int graph[][] = new int[N][N];
        int u = 0, v = 0;

        for (int i = 0; i < M; i++) {
            u = in.nextInt() - 1;
            v = in.nextInt() - 1;

            graph[u][v] = C;
            graph[v][u] = C;
        }

        in.close();
        int src = 0, dest = N - 1;
        shortestPath(graph, src, dest);

        int tmp = -1, s1 = -1, d1 = -1;
        List<Integer> list = new ArrayList<Integer>(edges);
        for (int i = 0; i < list.size() - 1; i++) {
            int s = list.get(i);
            int d = list.get(i + 1);
            if (tmp != -1) {
                graph[s1][d1] = tmp;
                graph[d1][s1] = tmp;
            }
            tmp = graph[s][d];
            s1 = s;
            d1 = d;
            graph[s][d] = 0;
            graph[d][s] = 0;
            shortestPath(graph, src, dest);
        }

        list = new ArrayList<Integer>(dists);
        int TOTAL = list.get(1);
        if (TOTAL != Integer.MAX_VALUE) {
            int t = T;
            int c = C;
            List<Character> col = new ArrayList<Character>();
            for (int i = 0; i < TOTAL + 1; i++) {
                col.add('#');
            }
            boolean on = true;
            for (int i = 1; i <= TOTAL; i++) {
                if (on == true)
                    col.set(i - 1, 'G');
                else
                    col.set(i - 1, 'R');
                if (i % t == 0) {
                    on = !on;
                }
            }
            int ans = 0;
            int i = 0;
            while (i <= TOTAL) {
                if (i == TOTAL) {
                    break;
                }
                if (col.get(i) == 'G') {
                    ans += c;
                } else {
                    int j = i;
                    int cnt = 0;
                    while (col.get(j) == 'R') {
                        j++;
                        cnt++;
                    }
                    ans += (cnt);
                    ans += c;
                }
                i += c;
            }
            System.out.println(ans);
        } else {
            System.out.println(-1);
        }
    }
}   