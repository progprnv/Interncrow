// JavaScript for toggling subdomains
document.addEventListener("DOMContentLoaded", function() {
    const mainDomainButtons = document.querySelectorAll(".main-domain-button");
  
    mainDomainButtons.forEach(button => {
      button.addEventListener("click", function() {
        const domainId = button.dataset.domainId;
        const subDomainList = document.querySelector(`#subdomains-${domainId}`);
  
        if (subDomainList) {
          if (subDomainList.classList.contains("hide")) {
            subDomainList.classList.remove("hide");
            button.textContent = "Hide Subdomains";
          } else {
            subDomainList.classList.add("hide");
            button.textContent = "Show Subdomains";
          }
        }
      });
    });
  });
  