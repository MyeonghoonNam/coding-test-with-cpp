const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `4 6
101111
101010
101011
111011`
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

    if (this.size === 1) {
      this.head = this.tail = null;
    } else {
      this.head = popNode.next;
    }

    this.size -= 1;

    return popNode.value;
  }

  isEmpty() {
    return this.size === 0 ? true : false;
  }
}

const solution = () => {
  const [N, M] = input().split(" ").map(Number);
  const maze = Array.from(new Array(N), () => new Array(M).fill(0));
  const visited = Array.from(new Array(N), () => new Array(M).fill(0));
  const dy = [-1, 0, 1, 0];
  const dx = [0, 1, 0, -1];

  const bfs = () => {
    const queue = new Queue();
    queue.enqueue([0, 0]);
    visited[0][0] = 1;

    while (queue.isEmpty() === false) {
      const [y, x] = queue.dequeue();

      for (let i = 0; i < 4; i++) {
        const ny = y + dy[i];
        const nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

        if (visited[ny][nx] === 0 && maze[ny][nx] === 1) {
          queue.enqueue([ny, nx]);
          visited[ny][nx] = visited[y][x] + 1;
        }
      }
    }
  };

  for (let i = 0; i < N; i++) {
    const row = input();

    for (let j = 0; j < M; j++) {
      maze[i][j] = Number(row[j]);
    }
  }

  bfs();

  const result = visited[N - 1][M - 1];

  return result;
};

console.log(solution());
