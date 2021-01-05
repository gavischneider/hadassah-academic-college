(() => {
  let date;
  window.addEventListener("DOMContentLoaded", () => {
    date = getDate();
    document
      .getElementById("submitPasswordButton")
      .addEventListener("click", handleSubmit);
    document.getElementById("warningMessage").style.display = "none";
  });

  // When the user clicked submit
  function handleSubmit() {
    removeErrorsFromDOM();
    let password = document.getElementById("passwordInput").value.trim();
    let verifyPassword = document
      .getElementById("verifyPasswordInput")
      .value.trim();

    console.log(`password: ${password}`);
    console.log(`verify password: ${verifyPassword}`);

    // Check if a minute has passed since page loaded
    const oneMinute = 60 * 1000;
    if (date - new Date() > oneMinute) {
      console.log("User took longer than one minute");
      window.location.replace("http://localhost:3000/auth/register");
    } else {
      let errors = validateForm(password, verifyPassword);
      if (errors.length > 0) {
        displayErrors(errors);
      } else {
        // If we get here, there are no errors, send data to server
        const urlParams = new URLSearchParams(window.location.search);
        const firstName = urlParams.get("firstName");
        const lastName = urlParams.get("lastName");
        const email = urlParams.get("email");
        fetch("http://localhost:3000/auth/register", {
          method: "POST",
          body: {
            firstName,
            lastName,
            email,
            password,
          },
        })
          .then((res) => res.json())
          .then((data) => {
            console.log(data);
            //JSON.stringify(data);
            window.location.replace(
              "http://localhost:3000/auth/login" + "success"
            );
          })
          .catch((err) => {
            console.log("Error registering new user: ", err);
            window.location.replace(
              "http://localhost:3000/auth/login" + "failure"
            );
          });
      }
    }
  }

  // Clean up all visible errors
  function removeErrorsFromDOM() {
    warningMessage = document.getElementById("warningMessage").style.display =
      "none";
    let listOfErrors = document.getElementById("list-of-errors");
    if (listOfErrors) {
      listOfErrors.parentElement.removeChild(listOfErrors);
    }
  }

  // Verify that everything is as expected
  function validateForm(password, verifyPassword) {
    // Validate
    let errors = [];

    if (!password) {
      errors.push("Please enter password");
    }
    if (!verifyPassword) {
      errors.push("Please verify password");
    }
    if (password.length < 8 || verifyPassword.length < 8) {
      errors.push("Password must be at least 8 characters");
    }
    if (password.localeCompare(verifyPassword) !== 0) {
      errors.push("Passwords must match");
    }

    return errors;
  }

  // Display relevant errors
  function displayErrors(errors) {
    listOfErrors = document.createElement("ul");
    listOfErrors.setAttribute("id", "list-of-errors");
    errors.map((error) => {
      newError = document.createElement("li");
      newError.textContent = error;
      listOfErrors.appendChild(newError);
    });
    let warningMessage = document.getElementById("warningMessage");
    warningMessage.appendChild(listOfErrors);
    warningMessage.style.display = "block";
  }

  function getDate() {
    return new Date();
  }
})();
