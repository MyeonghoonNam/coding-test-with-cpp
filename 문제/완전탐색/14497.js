const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `3 3
2 2 1 1
#00
0*0
000`
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

    this.size++;
  }

  dequeue() {
    if (this.size === 0) return;

    const popNode = this.head;
    this.head = popNode.next;

    if (this.size === 1) {
      this.tail = null;
    }

    this.size--;

    return popNode.value;
  }

  isEmpty() {
    return this.size === 0 ? true : false;
  }
}

function solution() {
  const [N, M] = input().split(" ").map(Number);
  const [y1, x1, y2, x2] = input()
    .split(" ")
    .map((value) => Number(value) - 1);

  const room = [];
  const visited = Array.from(new Array(N), () => new Array(M).fill(0));
  let time = 0;

  const dy = [1, -1, 0, 0];
  const dx = [0, 0, -1, 1];

  for (let i = 0; i < N; i++) {
    room.push(input().split(""));
  }

  let queue = new Queue();

  queue.enqueue({ y: y1, x: x1 });
  visited[y1][x1] = 1;

  while (room[y2][x2] !== "0") {
    time++;

    const temp = new Queue();

    while (!queue.isEmpty()) {
      const { y, x } = queue.dequeue();

      for (let i = 0; i < 4; i++) {
        const ny = y + dy[i];
        const nx = x + dx[i];

        if (nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx]) continue;

        if (room[ny][nx] !== "0") {
          temp.enqueue({ y: ny, x: nx });
          room[ny][nx] = "0";
        } else {
          queue.enqueue({ y: ny, x: nx });
        }

        visited[ny][nx] = time;
      }
    }

    queue = temp;
  }

  return visited[y2][x2];
}

console.log(solution());
