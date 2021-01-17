(() => {
  let counter;
  let firstName;
  let lastName;
  let email;
  window.addEventListener("DOMContentLoaded", () => {
    const urlParams = new URLSearchParams(window.location.search);
    firstName = urlParams.get("firstName");
    lastName = urlParams.get("lastName");
    email = urlParams.get("email");
    counter = 0;
    document
      .getElementById("submitPasswordButton")
      .addEventListener("click", handleSubmit);
    document.getElementById("warningMessage").style.display = "none";
  });

  // Increases counter by 1 every second
  setInterval(() => {
    counter++;
  }, 1000);

  // When the user clicks submit
  function handleSubmit(e) {
    removeErrorsFromDOM();
    let password = document.getElementById("passwordInput").value.trim();
    let verifyPassword = document
      .getElementById("verifyPasswordInput")
      .value.trim();

    // If the user took more than 1 minute, reroute them back to register page
    if (counter > 60) {
      return window.location.replace(
        "http://localhost:3000/auth/register?errorMessage=1"
      );
    } else {
      let errors = validateForm(password, verifyPassword);
      if (errors.length > 0) {
        e.preventDefault();
        displayErrors(errors);
      } else {
        // If we get here, there are no errors, send data to server
        fetch("http://localhost:3000/auth/password", {
          method: "POST",
          headers: {
            Accept: "application/json",
            "Content-Type": "application/json",
            "Access-Control-Origin": "*",
          },
          body: JSON.stringify({
            firstName: firstName,
            lastName: lastName,
            email: email,
            password: password,
          }),
        })
          .then((data) => {
            window.location.replace(
              "http://localhost:3000/auth/login?registered=success"
            );
          })
          .catch((err) => {
            console.log("Error registering new user: ", err);
            window.location.replace(
              "http://localhost:3000/auth/login?registered=failure"
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
})();
