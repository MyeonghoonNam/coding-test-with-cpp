const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `7 7
1011111
1110001
1000001
1000001
1000001
1000001
1111111`
).split("\n");

const input = (() => {
  let line = 0;
  return () => stdin[line++];
})();
