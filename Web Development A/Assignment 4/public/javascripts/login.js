(() => {
  window.addEventListener("DOMContentLoaded", () => {
    removeErrorsFromDOM();
    document
      .getElementById("loginButton")
      .addEventListener("click", handleSubmit);
    document.getElementById("warningMessage").style.display = "none";
    addMessage();
  });

  // When the user clicks submit
  function handleSubmit(e) {
    removeErrorsFromDOM();
    let email = document.getElementById("emailInput").value.trim();
    let password = document.getElementById("passwordInput").value.trim();

    let errors = validateForm(email, password);
    if (errors.length > 0) {
      displayErrors(errors);
      e.preventDefault();
    } else {
      // If we get here, there are no errors, send data to server
      fetch("http://localhost:3000/auth/login", {
        method: "POST",
        headers: {
          Accept: "application/json",
          "Content-Type": "application/json",
          "Access-Control-Origin": "*",
        },
        body: JSON.stringify({
          email: email,
          password: password,
        }),
      })
        .then((res) => res.json())
        .then((data) => {})
        .catch((err) => {
          console.log(err);
        });
    }
  }

  // Add relevant message to screen
  function addMessage() {
    const urlParams = new URLSearchParams(window.location.search);
    const message = urlParams.get("registered");
    let response = "";

    message.localeCompare("success") === 0
      ? (response = "You have successfully registered! Please log in.")
      : message.localeCompare("failure") === 0
      ? (response = "You took to long to register, please try again.")
      : "";

    let parent = document.getElementById("mes");
    let mes = document.createElement("h2");
    mes.textContent = response;
    parent.append(mes);
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
  function validateForm(email, password) {
    let errors = [];

    if (!email) {
      errors.push("Please enter email");
    }
    if (!password) {
      errors.push("Please enter password");
    }
    if (password && password.length < 8) {
      errors.push("Password must be at least 8 characters");
    }

    if (!validEmail(email)) {
      errors.push("Please enter a valid email address");
    }

    return errors;
  }

  // Validate email
  function validEmail(email) {
    const emailRegex = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    return emailRegex.test(email);
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
