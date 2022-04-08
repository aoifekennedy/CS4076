#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <algorithm>

template <typename T>
void addItem(vector<T> v, T t)
{
    v.push_back(t);
}

string randomRoom;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->textEdit_2->setTextColor(QColor("red"));
    ui->textEdit_3->setTextColor(QColor("green"));


    ui->textEdit->append(QString::fromStdString(zork->printWelcome() + "\n"));
    printCharacterStats();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    goRoom("South");
}

void MainWindow::on_pushButton_2_clicked()
{
    goRoom("West");
}

void MainWindow::on_pushButton_11_clicked()
{
    auto s = std::to_string(randomRoom);
    ui->textEdit->append(QString::fromStdString(s));
}

void MainWindow::on_pushButton_3_clicked()
{
    goRoom("North");
}

void MainWindow::on_pushButton_4_clicked()
{
    goRoom("East");
}


void MainWindow::on_pushButton_5_clicked()
{
    goRoom("teleport");
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->textEdit->append(QString::fromStdString(character.longDescription()));
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->textEdit->append(QString::fromStdString(zork->printInfo()));
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->textEdit->append(QString::fromStdString(zork->map() + "\n"));
}

void MainWindow::on_pushButton_9_clicked()
{
    addToContents = true;
    vector<Item> items = zork->getCurrentRoom().viewItems();
    listItems(items, "Room");
}

void MainWindow::on_pushButton_10_clicked()
{
    addToContents = false;
    vector<Item> items = character.viewItems();
    listItems(items, "character");
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem*item)
{
    string description = item->text().toStdString();
    Item i = *new Item(description);
    ui->listWidget->takeItem(ui->listWidget->row(item));

    if (addToContents)
    {
        Room r = zork->getCurrentRoom();
        Item m = r.findItem(i);
        addItem(character.itemsInCharacter, m);
        character.addItem(&m);
        r.removeItem(m);
        ui->textEdit->append(QString::fromStdString(description + " has been added to your inventory.\n"));

        if (description = "Banana", "Water", "Apple")
        {
            character.incrementHealth();
            ui->textEdit_3->setText(QString::fromStdString(displayHealth()));
        }
    }
    else
    {
        Item m = character.findItem(i);
        Room r = zork->getCurrentRoom();
        addItem(r.itemsInRoom, m);
        character.removeItem(m);
        ui->textEdit->append(QString::fromStdString(description + " has been removed from your inventory.\n"));
    }
}

void MainWindow::addItemsToListWidget(vector<Item> items)
{
    ui->listWidget->clear();

    if (addToContents)
    {
        if (!zork->getCurrentRoom().allItemsCollected())
        {
            for (unsigned int i = 0; (unsigned int)i < (unsigned int)zork->getCurrentRoom().numberOfItems(); i++)
            {
                ui->listWidget->addItem(QString::fromStdString(items[i].getShortDescription()));
            }
        }
        else {
            ui->textEdit->append(QString::fromStdString("There are no items in the room."));
        }
    }
    else
    {
        if (!character.itemsInCharacter.empty())
        {
            for (unsigned int i = 0; i < character.itemsInCharacter.size(); i++)
            {
                ui->listWidget->addItem(QString::fromStdString(items[i].getShortDescription()));
            }
        }
        else
        {
            ui->textEdit->append(QString::fromStdString("There are no items in " + character.shortDescription() + "'s inventory.\n"));
        }
    }
}

void MainWindow::endGameState(string message1, string message2)
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->listWidget->setEnabled(false);

    ui->textEdit->setText(QString::fromStdString(character.description + " has " + message1 + ". You have " + message2));

    character.Health = 0;
    character.Lives = 0;
    ui->textEdit_2->setText(QString::fromStdString(displayLives()));
    ui->textEdit_3->setText(QString::fromStdString(displayHealth()));
}

void MainWindow::goRoom(string direction)
{
    string randRoomDescription;
        if (randomRoom == 1)
        {
            randRoomDescription = "A";
        }

        if (randomRoom == 2)
        {
            randRoomDescription = "B";
        }

        if (randomRoom == 3)
        {
            randRoomDescription="C";
        }

        if (randomRoom == 4)
        {
            randRoomDescription="D";
        }

        if (randomRoom == 5)
        {
            randRoomDescription="E";
        }

        if (randomRoom == 6)
        {
            randRoomDescription="F";
        }

        if (randomRoom == 7)
        {
            randRoomDescription="G";
        }

        if (randomRoom == 8)
        {
            randRoomDescription="H";
        }

        if (randomRoom == 9)
        {
            randRoomDescription="I";
        }

        if (randomRoom == 10)
        {
            randRoomDescription="J";
        }

        if (character.Lives != 0 && character.Health >= 0)
        {
            character.decrementHealth();
            printCharacterStats();

            if (direction == "teleport")
            {
                ui->textEdit->append(QString::fromStdString(zork->teleport() + "\n"));
            }
            else
            {
                ui->textEdit->append(QString::fromStdString(zork->go(direction) + "\n"));

                if (zork->getCurrentRoom().description == randRoomDescription)
                {
                    endGameState("found the Winning Room!", "won the game! Congratulations!");
                }
            }
        }
        else
        {
            endGameState("ran out of lives.", "lost the game:(");
        }
}

void MainWindow::listItems(vector<Item> items, QString description)
{
    if (!items.empty())
    {
        addItemsToListWidget(items);
    }
    else
    {
        //ui->textEdit->append("No " + description + " items could be found.\n");
        ui->textEdit->append("There are no items in this room.\n");
    }
}

string MainWindow::displayHealth()
{
    string output = "Health:\n";

    for (int i = 0; i < character.Health; i++)
    {
        output += "[] ";
    }

    return output;
}

string MainWindow::displayLives()
{
    string output = "Lives:\n";

    for (int i = 0; i < character.getLives(); i++)
    {
        output += "+ ";
    }

    return output;
}

void MainWindow::printCharacterStats()
{
    if (!(character.Lives > 0))
    {

    }
    else
    {
        ui->textEdit_2->setText(QString::fromStdString(displayLives()));
        ui->textEdit_3->setText(QString::fromStdString(displayHealth()));
    }
}
