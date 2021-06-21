window.addEventListener("DOMContentLoaded", () =>{
    document.getElementById("add-button").addEventListener("click", addMessage);
    getMessages();
    getOnlineUsers()
    window.setInterval(function(){
        getMessages();
        getOnlineUsers();
    }, 5000);
})

window.onbeforeunload = function(e) {
    fetch("http://localhost:8080/logout", {
        method: "GET",
    }).then()
};

function getOnlineUsers(){
    fetch("http://localhost:8080/user/online", {
        method: "GET",
    }).then((res) => {
        return res.json();
    }).then((users) => {
        let usersContainer = document.getElementById("users-container");
        let userList = document.createElement("ul");
        users.map((user) => {
            let newUser = document.createElement("li");
            newUser.innerHTML = user.username;
            userList.append(newUser);
        })
        usersContainer.innerHTML = '';
        usersContainer.append(userList);
    })
}

function getMessages(){
    fetch("http://localhost:8080/message/last-five", {
        method: "GET",
    }).then((res) => {
        return res.json();
    }).then((messages) => {
        // Add messages to DOM
        let messageContainer = document.getElementById("message-container");
        let messageList = document.createElement("ul");
        messages.map((message) => {
            let newMessage = document.createElement("li");
            newMessage.innerHTML = message.user + " " + message.body;
            messageList.append(newMessage);
        })
        messageContainer.innerHTML = '';
        messageContainer.append(messageList);
    })
}

function addMessage(){
    let username = document.getElementById("username-input").value.trim();
    let body = document.getElementById("body-input").value.trim();

    document.getElementById("body-input").value = "";

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