window.addEventListener("DOMContentLoaded", () =>{
    document.getElementById("add-button").addEventListener("click", addMessage);
    document.getElementById("logout-button").addEventListener("click", logout);
    document.getElementById("search-button").addEventListener("click", search);
    getMessages();
    getOnlineUsers()
    window.setInterval(function(){
        getOnlineUsers();
        getMessages();
    }, 5000);
    window.setInterval(function () {
        checkSession();
    }, 3000);
})

// When tab/browser is closed, log the user out
window.onbeforeunload = function(e) {
    logout();
};

// Check if theres a user logged in
function checkSession(){
    fetch("http://localhost:8080/session", {
        method: "GET",
    }).then((res) => {
        return res.json();
    }).then((result) => {
        if(!result) {
            logout();
        }
    })
}

function logout() {
    fetch("http://localhost:8080/logout", {
        method: "POST",
        headers: {
            Accept: "application/json",
            "Content-Type": "application/json",
            "Access-Control-Origin": "*",
        }
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
        userList.classList.add("list-group");
        users.map((user) => {
            let newUser = document.createElement("li");
            newUser.innerHTML = user.username;
            newUser.classList.add("list-group-item");
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
        messages.reverse();
        let index = 1;
        let messageContainer = document.getElementById("message-container");
        let messageList = document.createElement("ul");
        messageList.classList.add("list-group")
        messages.map((message) => {
            let newMessage = document.createElement("li");
            newMessage.innerHTML = message.user + ": " + message.body;
            newMessage.classList.add("list-group-item");
            if(index % 2 === 0) {
                newMessage.classList.add("list-group-item-dark");
            }
            index++;
            messageList.append(newMessage);
        })
        messageContainer.innerHTML = '';
        messageContainer.append(messageList);
    })
}

function addMessage(){
    let username = document.getElementById("username-input").value.trim();
    let body = document.getElementById("body-input").value.trim();
    if (body === "") {
        alert("Message may not be empty!");
        return false;
    }
    document.getElementById("body-input").value = "";

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
    fetch("http://localhost:8080/search/user?query=" + query, {
        method: "GET",
        headers: {
            Accept: "application/json",
            "Content-Type": "application/json",
            "Access-Control-Origin": "*",
        }
    }).then((res) => {
        return res.json();
    }).then((users) => {
        let container = document.getElementById("user-results-container");
        let searchUserList = document.createElement("ul");
        searchUserList.classList.add("list-group");
        users.map((user) => {
            let newUser = document.createElement("li");
            newUser.innerHTML = user.username;
            newUser.classList.add("list-group-item")
            searchUserList.append(newUser);
        })
        container.innerHTML = '';
        container.append(searchUserList);
    })
}

function searchMessagesByBody(query){
    fetch("http://localhost:8080/search/message/body?query=" + query, {
        method: "GET",
        headers: {
            Accept: "application/json",
            "Content-Type": "application/json",
            "Access-Control-Origin": "*",
        }
    }).then((res) => {
        return res.json();
    }).then((messages) => {
        let container = document.getElementById("message-body-results-container");
        let searchMessageList = document.createElement("ul");
        searchMessageList.classList.add("list-group")
        messages.map((message) => {
            let newMessage = document.createElement("li");
            newMessage.innerHTML = message.user + ": " + message.body;
            newMessage.classList.add("list-group-item")
            searchMessageList.append(newMessage);
        })
        container.innerHTML = '';
        container.append(searchMessageList);
    })
}

function searchMessagesByUser(query){
    fetch("http://localhost:8080/search/message/user?query=" + query, {
        method: "GET",
        headers: {
            Accept: "application/json",
            "Content-Type": "application/json",
            "Access-Control-Origin": "*",
        }
    }).then((res) => {
        return res.json();
    }).then((messages) => {
        let container = document.getElementById("message-user-results-container");
        let searchMessageByUserList = document.createElement("ul");
        searchMessageByUserList.classList.add("list-group");
        messages.map((message) => {
            let newMessage = document.createElement("li");
            newMessage.innerHTML = message.user + ": " + message.body;
            newMessage.classList.add("list-group-item")
            searchMessageByUserList.append(newMessage);
        })
        container.innerHTML = '';
        container.append(searchMessageByUserList);
    })
}

function search(){
    let query = document.getElementById("query-input").value.trim();
    searchUsersByName(query);
    searchMessagesByBody(query);
    searchMessagesByUser(query);
}
