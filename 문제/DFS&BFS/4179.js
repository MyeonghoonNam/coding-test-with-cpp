const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `4 4
####
#JF#
#..#
#..#`
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
  const [R, C] = input().split(" ").map(Number);
  const maze = [];
  const human = Array.from(new Array(R), () => new Array(C).fill(0));
  const fire = Array.from(new Array(R), () =>
    new Array(C).fill(Number.MAX_SAFE_INTEGER)
  );
  const queue = new Queue();
  const dy = [-1, 1, 0, 0];
  const dx = [0, 0, -1, 1];
  let sy = 0;
  let sx = 0;
  let ret = 0;

  function isValidMapRange(y, x) {
    if (y < 0 || y >= R || x < 0 || x >= C) return false;
    return true;
  }

  function isPosMazeEnd(y, x) {
    if (y === 0 || y === R - 1 || x === 0 || x === C - 1) return true;
    return false;
  }

  for (let i = 0; i < R; i++) {
    const row = input();
    maze.push(row);

    for (let j = 0; j < C; j++) {
      if (maze[i][j] === "J") {
        sy = i;
        sx = j;
        human[i][j] = 1;
      } else if (maze[i][j] === "F") {
        queue.enqueue([i, j]);
        fire[i][j] = 1;
      }
    }
  }

  // 불의 최단거리
  while (!queue.isEmpty()) {
    const [y, x] = queue.dequeue();

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];

      if (!isValidMapRange(ny, nx)) continue;
      if (fire[ny][nx] !== Number.MAX_SAFE_INTEGER) continue;

      if (maze[ny][nx] === ".") {
        fire[ny][nx] = fire[y][x] + 1;
        queue.enqueue([ny, nx]);
      }
    }
  }

  // 사람의 최단거리
  queue.enqueue([sy, sx]);

  while (!queue.isEmpty()) {
    const [y, x] = queue.dequeue();

    if (isPosMazeEnd(y, x)) {
      ret = human[y][x];
      break;
    }

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];

      if (!isValidMapRange(ny, nx)) continue;
      if (maze[ny][nx] === "#") continue;

      if (human[y][x] + 1 < fire[ny][nx]) {
        human[ny][nx] = human[y][x] + 1;
        queue.enqueue([ny, nx]);
      }
    }
  }

  if (ret === 0) {
    ret = "IMPOSSIBLE";
  }

  return ret;
}

console.log(solution());
