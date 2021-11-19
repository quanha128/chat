var obj = new XMLHttpRequest();

obj.open("GET", "http://marinesnow.sakura.ne.jp/2019/sample.php");
obj.onload = function () {
  var data = JSON.parse(this.responseText);
  var english = data[0].score;
  document.getElementById('score').innerText = english;
}
obj.send(null);
document.getElementById('comment').innerText = "Study hard!";
