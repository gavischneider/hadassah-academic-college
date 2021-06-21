window.addEventListener("DOMContentLoaded", () =>{
    document.getElementById("add-button").addEventListener("click", addMessage);
    document.getElementById("logout-button").addEventListener("click", logout);
    getMessages();
    getOnlineUsers()
    window.setInterval(function(){
        getMessages();
        getOnlineUsers();
    }, 5000);
})

// When tab/browser is closed, log the user out
window.onbeforeunload = function(e) {
    logout();
};

function logout() {
    fetch("http://localhost:8080/logout", {
        method: "GET",
    }).then(() => {
        window.location.replace("http://localhost:8080/login");
    })
}

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

function searchUsersByName(query){
    fetch("http://localhost:8080/search/user", {
        method: "POST",
        headers: {
            Accept: "application/json",
            "Content-Type": "application/json",
            "Access-Control-Origin": "*",
        },
        body: JSON.stringify({
            query: query
        })
    }).then((res) => {
        return res.json();
    }).then((results) => {
        ////
    })
}

function searchMessagesByBody(query){
    fetch("http://localhost:8080/search/message/body", {
        method: "POST",
        headers: {
            Accept: "application/json",
            "Content-Type": "application/json",
            "Access-Control-Origin": "*",
        },
        body: JSON.stringify({
            query: query
        })
    }).then((res) => {
        return res.json();
    }).then((results) => {
        ////
    })
}

function searchMessagesByUser(query){
    fetch("http://localhost:8080/search/message/user", {
        method: "POST",
        headers: {
            Accept: "application/json",
            "Content-Type": "application/json",
            "Access-Control-Origin": "*",
        },
        body: JSON.stringify({
            query: query
        })
    }).then((res) => {
        return res.json();
    }).then((results) => {
        ////
    })
}

function search(){
    let query = document.getElementById("query-input").value.trim();
    searchUsersByName(query);
    searchMessagesByBody(query);
    searchMessagesByUser(query);
}