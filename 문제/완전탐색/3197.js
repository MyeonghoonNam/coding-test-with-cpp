const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `8 17
...XXXXXX..XX.XXX
....XXXXXXXXX.XXX
...XXXXXXXXXXXX..
..XXXXX.LXXXXXX..
.XXXXXX..XXXXXX..
XXXXXXX...XXXX...
..XXXXX...XXX....
....XXXXX.XXXL...`
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

    if (this.isEmpty()) {
      this.head = this.tail = newNode;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }

    this.size++;
  }

  dequeue() {
    if (this.isEmpty()) return;

    const popNode = this.head;
    this.head = popNode.next;
    this.size--;

    if (this.isEmpty()) {
      this.head = this.tail = null;
    }

    return popNode.value;
  }

  isEmpty() {
    return this.size === 0 ? true : false;
  }
}

function solution() {
  const [R, C] = input().split(" ").map(Number);
  const lake = [];
  let swanY = 0;
  let swanX = 0;
  let day = 0;

  const dy = [-1, 1, 0, 0];
  const dx = [0, 0, -1, 1];

  let waterQueue = new Queue();
  let waterTempQueue = new Queue();
  let swanQueue = new Queue();
  let swanTempQueue = new Queue();

  const visitedWater = Array.from(new Array(R), () => new Array(C).fill(0));
  const visitedSwan = Array.from(new Array(R), () => new Array(C).fill(0));

  for (let i = 0; i < R; i++) {
    const row = input().split("");

    lake.push(row);

    for (let j = 0; j < C; j++) {
      const space = row[j];

      if (space === "L") {
        swanY = i;
        swanX = j;
      }

      if (space === "." || space === "L") {
        waterQueue.enqueue([i, j]);
        visitedWater[i][j] = 1;
      }
    }
  }

  function moveSwan() {
    while (!swanQueue.isEmpty()) {
      const [y, x] = swanQueue.dequeue();

      for (let i = 0; i < 4; i++) {
        const ny = y + dy[i];
        const nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
        if (visitedSwan[ny][nx]) continue;

        visitedSwan[ny][nx] = 1;

        if (lake[ny][nx] === ".") {
          swanQueue.enqueue([ny, nx]);
        } else if (lake[ny][nx] === "X") {
          swanTempQueue.enqueue([ny, nx]);
        } else if (lake[ny][nx] === "L") {
          return true;
        }
      }
    }

    swanQueue = swanTempQueue;
    swanTempQueue = new Queue();

    return false;
  }

  function meltIce() {
    while (!waterQueue.isEmpty()) {
      const [y, x] = waterQueue.dequeue();

      for (let i = 0; i < 4; i++) {
        const ny = y + dy[i];
        const nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
        if (visitedWater[ny][nx]) continue;

        if (lake[ny][nx] === "X") {
          lake[ny][nx] = ".";
          visitedWater[ny][nx] = 1;
          waterTempQueue.enqueue([ny, nx]);
        }
      }
    }

    waterQueue = waterTempQueue;
    waterTempQueue = new Queue();
  }

  swanQueue.enqueue([swanY, swanX]);
  visitedSwan[swanY][swanX] = 1;

  while (true) {
    if (moveSwan()) break;
    meltIce();
    day++;
  }

  return day;
}

console.log(solution());
