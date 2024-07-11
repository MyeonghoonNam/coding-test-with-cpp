const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7`
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
  const N = Number(input());
  const map = [];
  let visited = Array.from(new Array(N), () => new Array(N).fill(0));
  const dy = [-1, 0, 1, 0];
  const dx = [0, 1, 0, -1];
  let result = 1;

  function bfs(i, j, h) {
    const queue = new Queue();
    queue.enqueue([i, j]);
    visited[i][j] = 1;

    while (!queue.isEmpty()) {
      const [y, x] = queue.dequeue();

      for (let i = 0; i < 4; i++) {
        const ny = y + dy[i];
        const nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

        if (map[ny][nx] > h && !visited[ny][nx]) {
          queue.enqueue([ny, nx]);
          visited[ny][nx] = 1;
        }
      }
    }
  }

  for (let i = 0; i < N; i++) {
    const row = input().split(" ").map(Number);
    map.push(row);
  }

  for (let h = 1; h < 101; h++) {
    let count = 0;
    visited = Array.from(new Array(N), () => new Array(N).fill(0));

    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        if (map[i][j] > h && !visited[i][j]) {
          bfs(i, j, h);
          count += 1;
        }
      }
    }

    result = Math.max(result, count);
  }

  return result;
}

console.log(solution());
