// Toast function
function toast({ type = "info", title = "", message = "", duration = 3000 }) {
  const main = document.getElementById("toast");
  if (main) {
    const toast = document.createElement("div");
    const totalDuration = duration + 1000;

    // Auto remove toast
    setTimeout(function () {
      main.removeChild(toast);
    }, totalDuration);

    // Remove toast when click
    toast.onclick = function (e) {
      if (e.target.closest(".toast__close")) {
        main.removeChild(toast);
      }
    };

    const icons = {
      success: "fa-solid fa-circle-check",
      error: "fa-solid fa-circle-xmark",
      info: "fa-solid fa-info-circle",
      warning: "fa-solid fa-exclamation-triangle"
    };
    const icon = icons[type];
    const delay = (duration / 1000).toFixed(2);

    toast.classList.add("toast", `toast--${type}`);
    toast.style.animation = `slideInLeft ease .3s, fadeOut linear 1s ${delay}s forwards`;

    toast.innerHTML = `
                    <div class="toast__icon">
                        <i class="${icon}"></i>
                    </div>
                    <div class="toast__body">
                        <h3 class="toast__title">${title}</h3>
                        <p class="toast__msg">${message}</p>
                    </div>
                    <div class="toast__close">
                        <i class="fa-solid fa-xmark"></i>
                    </div>
                `;
    main.appendChild(toast);
  }
}

function showSuccessToast() {
  toast({
    type: "success",
    title: "Thành công",
    message: "Bạn đã đăng ký thành công tài khoản!",
    duration: 5000,
  });
}

function showErrorToast() {
  toast({
    type: "error",
    title: "Thất bại",
    message: "Bạn đã đăng ký tài khoản thất bại!",
    duration: 5000,
  });
}
