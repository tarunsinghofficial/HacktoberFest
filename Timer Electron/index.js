const electron = require('electron')
const path = require('electron')

const { app, BrowserWindow, Tray } = electron

let mainWindow
    // let tray = null

app.on('ready', () => {
    mainWindow = new BrowserWindow({
        webPreferences: {
            nodeIntegration: true,
            contextIsolation: false
        },
        height: 500,
        width: 300,
        frame: false,
        resizable: false
    })
    mainWindow.loadURL(`file://${__dirname}/src/index.html`)
})