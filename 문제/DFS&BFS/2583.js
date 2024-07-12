const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `5 7 3
0 2 4 4
1 1 2 5
4 0 6 2`
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
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  enqueue(value) {
    const newNode = new Node(value);

    if (this.size === 0) {
      this.head = this.tail = newNode;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }

    this.size += 1;
  }

  dequeue() {
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

function solution() {
  const [M, N, K] = input().split(" ").map(Number);
  const map = Array.from(new Array(M), () => new Array(N).fill(0));
  const visited = Array.from(new Array(M), () => new Array(N).fill(0));
  const ret = [];

  const dy = [-1, 0, 1, 0];
  const dx = [0, 1, 0, -1];

  function bfs(startY, startX) {
    const queue = new Queue();
    queue.enqueue([startY, startX]);
    visited[startY][startX] = 1;

    let area = 1;

    while (!queue.isEmpty()) {
      const [y, x] = queue.dequeue();

      for (let i = 0; i < 4; i++) {
        const ny = y + dy[i];
        const nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;

        if (map[ny][nx] === 0 && !visited[ny][nx]) {
          queue.enqueue([ny, nx]);
          visited[ny][nx] = 1;
          area += 1;
        }
      }
    }

    return area;
  }

  for (let i = 0; i < K; i++) {
    const [x1, y1, x2, y2] = input().split(" ").map(Number);

    for (let y = y1; y < y2; y++) {
      for (let x = x1; x < x2; x++) {
        map[y][x] = 1;
      }
    }
  }

  for (let y = 0; y < M; y++) {
    for (let x = 0; x < N; x++) {
      if (map[y][x] === 0 && !visited[y][x]) {
        ret.push(bfs(y, x));
      }
    }
  }

  ret.sort((a, b) => a - b);

  return `${ret.length}\n${ret.join(" ")}`;
}

console.log(solution());
