
#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct SV {
    string hoten;
    int ma;
    float d1, d2, d3;
};

struct Node {
    SV infor;
    Node *link;
};

struct List {
    Node *head;
    Node *tail;
};

void KhoiTao(List &l) {
    l.head = NULL;
    l.tail = NULL;
}

Node* TaoNode(SV x) {
    Node *p = new Node;
    p->infor = x;
    p->link = NULL;
    return p;
}

void ThemCuoi(List &l, SV x) {
    Node *p = TaoNode(x);

    if (l.head == NULL) {
        l.head = p;
        l.tail = p;
    }
    else {
        l.tail->link = p;
        l.tail = p;
    }
}

void Nhap(List &l, int n) {
    for (int i = 0; i < n; i++) {
        SV sv;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nNhap ho ten: ";
        getline(cin, sv.hoten);

        cout << "Nhap ma sinh vien: ";
        cin >> sv.ma;

        cout << "Nhap diem 1: ";
        cin >> sv.d1;

        cout << "Nhap diem 2: ";
        cin >> sv.d2;

        cout << "Nhap diem 3: ";
        cin >> sv.d3;

        ThemCuoi(l, sv);
    }
}

void Xuat(List l) {
    Node *p = l.head;

    while (p != NULL) {
        cout << "\nHo ten: " << p->data.hoten;
        cout << "\nMa sinh vien: " << p->data.ma;
        cout << "\nDiem 1: " << p->data.d1;
        cout << "\nDiem 2: " << p->data.d2;
        cout << "\nDiem 3: " << p->data.d3;
        cout << "\n-------------------";

        p = p->link;
    }
}

void GiaiPhong(List &l) {
    Node *p;

    while (l.head != NULL) {
        p = l.head;
        l.head = l.head->link;
        delete p;
    }

    l.tail = NULL;
}

int main() {
    List l;
    int n;

    KhoiTao(l);

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    Nhap(l, n);

    cout << "\nDANH SACH SINH VIEN";
    Xuat(l);

    GiaiPhong(l);

    return 0;
}
