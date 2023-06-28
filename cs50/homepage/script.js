// Start and Stop Changing Background
let intervalId;

function startChangingBackground() {
  intervalId = setInterval(changeBackgroundColor, 1000);
  alert("Color change started");
}

function stopChangingBackground() {
  clearInterval(intervalId);
  alert("Color change stopped");
}

function changeBackgroundColor() {
  const colors = ['#ff0000', '#00ff00', '#0000ff', '#ffff00', '#00ffff'];
  const randomIndex = Math.floor(Math.random() * colors.length);
  document.body.style.backgroundColor = colors[randomIndex];
}

// Event Listeners
document.addEventListener('DOMContentLoaded', function() {
  document.getElementById('startBtn').addEventListener('click', startChangingBackground);
  document.getElementById('stopBtn').addEventListener('click', stopChangingBackground);
});
