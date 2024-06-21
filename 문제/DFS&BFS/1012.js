const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `1
5 3 6
0 2
1 2
2 2
3 2
4 2
4 0`
).split("\n");

const input = (() => {
  let line = 0;
  return () => stdin[line++];
})();

class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.head = this.tail = null;
    this.size = 0;
  }

  enqueue(value) {
    const newNode = new Node(value);

    if (this.isEmpty()) {
      this.head = this.tail = newNode;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }

    this.size += 1;

    return;
  }

  dequeue() {
    if (this.isEmpty()) return;

    const popNode = this.head;
    this.head = popNode.next;

    if (this.size === 1) {
      this.tail = null;
    }

    this.size -= 1;

    return popNode.value;
  }

  isEmpty() {
    return this.size === 0 ? true : false;
  }
}

const solution = () => {
  let T = Number(input());

  const dy = [-1, 0, 1, 0];
  const dx = [0, 1, 0, -1];

  while (T--) {
    const [M, N, K] = input().split(" ").map(Number);
    const map = Array.from(new Array(N), () => new Array(M).fill(0));
    const visited = Array.from(new Array(N), () => new Array(M).fill(0));
    let result = 0;

    const bfs = (startY, startX) => {
      const queue = new Queue();
      queue.enqueue([startY, startX]);
      visited[startY][startX] = 1;

      while (queue.isEmpty() === false) {
        const [y, x] = queue.dequeue();

        for (let i = 0; i < 4; i++) {
          const ny = y + dy[i];
          const nx = x + dx[i];

          if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

          if (visited[ny][nx] === 0 && map[ny][nx] === 1) {
            queue.enqueue([ny, nx]);
            visited[ny][nx] = 1;
          }
        }
      }

      return;
    };

    for (let i = 0; i < K; i++) {
      const [X, Y] = input().split(" ").map(Number);
      map[Y][X] = 1;
    }

    for (let i = 0; i < N; i++) {
      for (let j = 0; j < M; j++) {
        if (visited[i][j] === 0 && map[i][j] === 1) {
          bfs(i, j);
          result += 1;
        }
      }
    }

    console.log(result);
  }
};

solution();
