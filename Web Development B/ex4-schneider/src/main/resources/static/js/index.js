window.addEventListener("DOMContentLoaded", () =>{
    alert("Hello!!")
    document.getElementById("add-button").addEventListener("click", addMessage);
    getMessages();
})

function getMessages(){
    fetch("http://localhost:8080/message/last-five", {
        method: "GET",
    }).then((res) => {
        return res.json();
    }).then((messages) => {
        // Add messages to DOM
        let messageContainer = document.getElementById("message-container");
        messages.map((message) => {
            alert(message.body);
        })
    })
}

function addMessage(){
    let username = document.getElementById("username-input").value.trim();
    let body = document.getElementById("body-input").value.trim();

    console.log("-----")
    console.log(username);
    console.log(body);

    fetch("http://localhost:8080/message/add", {
        method: "POST",
        headers: {
            Accept: "application/json",
            "Content-Type": "application/json",
            "Access-Control-Origin": "*",
        },
        body: JSON.stringify({
            user: username,
            body: body
        }),
    }).then(() => {
            getMessages()
        })
        .catch((err) => {
            console.log(err);
        });
}