#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;
struct node {
    string username;
    string password;
    node* next;

    node(const string& uname, const string& pwd);
};
struct Commit {
    string msg;
    time_t Time;
    Commit* next;

    Commit(const string& mesg);
};
struct File {
    string filename;
    File* next;

    File(const string& name);
};
struct Repository {
    string name;
    bool isPublic;
    int forkC;
    int commitC;
    int views;
    File* files;
    Commit* commits;
    string comments[100];
    string likes[100];
    string viewers[100];
    Repository* left;
    Repository* right;

    Repository(const string& repoName, bool visibility);
    ~Repository();
};
struct Tree {
    string userN;
    Repository* Repo;
    Tree* left;
    Tree* right;
    Tree(const string& uname, Repository* repo);
    ~Tree();
};
class HashTable {
public:
    static const int size = 100;
    node* table[size];
    Tree* userRepo[size];
    pair<string, string> followR[100];
    int count;
    int hashFunction(const string& key);
    HashTable();
    bool registerUser(const string& Uname, const string& pswd);
    bool login(const string& Uname, const string& pswd);
    void logout(const string& Uname);
    void createRepo(const string& Uname);
    void viewRepo(const string& username);
    void follow(const string& folwr, const string& folwed);
    void unfollow(const string& folwr, const string& folwed);
    void showFollower(const string& Uname);
    void showFollowing(const string& Uname);
    void showFollowers(const string& Uname);
    void updateFollower(const string& Uname);
    void deleteRepo(const string& Uname, const string& repoName);
    Tree* deleteRepofunc(Tree* root, const string& repoName);
    void insertRepo(Tree*& root, Tree* newNode);
    int FileCnt(File* head);
    int countLikes(const string likes[]);
    int countViewers(const string viewers[]);
    void viewRepofunc(Tree* root);
};

