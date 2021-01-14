(() => {
  window.addEventListener("DOMContentLoaded", () => {
    document
      .getElementById("submitButton")
      .addEventListener("click", handleSubmit);
    document.getElementById("warningMessage").style.display = "none";
    addMessage();
  });
})();

// When the user clicked submit
function handleSubmit(e) {
  console.log(e);
  removeErrorsFromDOM();
  let email = document.getElementById("emailInput").value.trim();
  let firstName = document.getElementById("firstNameInput").value.trim();
  let lastName = document.getElementById("lastNameInput").value.trim();

  console.log(`email: ${email}`);
  console.log(`first name: ${firstName}`);
  console.log(`last name: ${lastName}`);

  let errors = validateForm(email, firstName, lastName);
  if (errors.length > 0) {
    e.preventDefault();
    displayErrors(errors);
  } else {
    // If we get here, there are no errors, send data to server for validation
    fetch("http://localhost:3000/auth/lookup", {
      method: "POST",
      headers: {
        Accept: "application/json",
        "Content-Type": "application/json",
        "Access-Control-Origin": "*",
      },
      body: JSON.stringify({
        email: email,
      }),
    })
      .then((res) => {
        console.log("Heres the res - after lookup (frontend): ");
        console.log(res.status);
        if (res.status !== 200) {
          // Email is already in use
          displayErrors([
            "Email is already in use, please use a different email",
          ]);
        } else {
          // Email is not in use
          window.location.replace(
            `http://localhost:3000/auth/password?firstName=${firstName}&lastName=${lastName}&email=${email}`
          );
        }
      })
      .catch((err) => {
        console.log(`Error looking up the user, ${err}`);
      });
  }
}

// Add relevant message to screen
function addMessage() {
  console.log("IN THE ADD MESSAGE FUNCTION");
  const urlParams = new URLSearchParams(window.location.search);
  const message = urlParams.get("errorMessage");
  let response = "";

  console.log("THE REGISTERED MESSAGE");
  console.log(message);

  message.localeCompare("1") === 0
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
function validateForm(email, firstName, lastName) {
  // Validate
  let errors = [];

  if (email === "") {
    errors.push("Email is missing");
  }
  if (!firstName) {
    errors.push("First name is missing");
  }
  if (!lastName) {
    errors.push("Last name is missing");
  }

  if (firstName && validName(firstName)) {
    errors.push("First name may not contain numbers");
  }

  if (lastName && validName(lastName)) {
    errors.push("Last name may not contain numbers");
  }

  if (!validEmail(email)) {
    errors.push("Please enter a valid email address");
  }

  return errors;
}

// Validate names
function validName(name) {
  const numbersRegex = /\d/g;
  return numbersRegex.test(name);
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
