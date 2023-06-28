const videoPlayer = document.querySelector('.video-stream.html5-main-video');
videoPlayer.addEventListener('mouseenter', () => {
  videoPlayer.style.cursor = 'auto';
});
videoPlayer.addEventListener('mouseleave', () => {
  videoPlayer.style.cursor = '';
});
