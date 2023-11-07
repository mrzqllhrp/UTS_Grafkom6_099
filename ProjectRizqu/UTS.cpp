#include <GL/glut.h>

class Vehicle {
public:
    float x;
    float y;

    Vehicle() : x(0.0), y(-0.8) { }

    void draw() {
        // Gambar badan kendaraan
        glColor3f(0.0, 0.0, 1.0); // Warna biru
        glBegin(GL_POLYGON);
        glVertex2f(-0.2, -0.1);
        glVertex2f(-0.2, 0.1);
        glVertex2f(0.2, 0.1);
        glVertex2f(0.2, -0.1);
        glEnd();

        // Gambar jendala mobil
        glColor3f(0.0, 0.7, 0.7); // Warna hijau
        glBegin(GL_POLYGON);
        glVertex2f(-0.1, -0.05);
        glVertex2f(-0.1, 0.05);
        glVertex2f(0.1, 0.05);
        glVertex2f(0.1, -0.05);
        glEnd();

        // Gambar ban kiri
        glColor3f(0.0, 0.0, 0.0); // Warna hitam
        glTranslatef(-0.15, -0.1, 0.0);
        glutSolidTorus(0.025, 0.05, 10, 25);

        // Gambar ban kanan
        glTranslatef(0.3, 0.0, 0.0); // Pindah ke posisi velg ban kanan
        glutSolidTorus(0.025, 0.05, 10, 25);
    }

    void moveLeft() {
        x -= 0.05; // Geser kendaraan ke kiri
    }

    void moveDown() {
        y -= 0.05; // Geser kendaraan ke bawah
    }

    void moveUp() {
        y += 0.05; // Geser kendaraan ke atas
    }

    void moveRight() {
        x += 0.05; // Geser kendaraan ke kanan
    }
};

class Rocket {
public:
    float x;
    float y;

    Rocket() : x(0.0), y(0.0) { }

    void draw() {
        // Gambar kepala roket
        glColor3f(1.0, 0.0, 0.0); // Warna merah
        glBegin(GL_POLYGON);
        glVertex2f(-0.1, 0.0);   // Puncak kepala roket
        glVertex2f(0.0, 0.2);    // Kaki kepala roket
        glVertex2f(0.1, 0.0);    // Puncak kepala roket
        glEnd();

        // Gambar badan roket 
        glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0); // Warna merah pada atas
        glVertex2f(-0.05, 0.0);
        glVertex2f(-0.05, -0.2);
        glVertex2f(0.05, -0.2);
        glVertex2f(0.05, 0.0);
        glEnd();

        // Gambar sayap kiri
        glColor3f(1.0, 0.0, 0.0); // Warna merah
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.05, -0.05);
        glVertex2f(-0.1, -0.2);
        glVertex2f(0.0, -0.1);
        glEnd();

        // Gambar sayap kanan
        glBegin(GL_TRIANGLES);
        glVertex2f(0.05, -0.05);
        glVertex2f(0.1, -0.2);
        glVertex2f(0.0, -0.1);
        glEnd();

        // Gambar asap roket
        glColor3f(0.5, 0.5, 0.5); // Warna abu-abu
        glBegin(GL_POLYGON);
        glVertex2f(-0.02, -0.2);
        glVertex2f(-0.02, -0.25);
        glVertex2f(0.02, -0.25);
        glVertex2f(0.02, -0.2);
        glEnd();
    }


    void moveUp() {
        y += 0.05; // Geser roket ke atas
    }

    void moveDown() {
        y -= 0.05; // Geser roket ke bawah
    }
};

class Plane {
public:
    float x;
    float y;

    Plane() : x(0.0), y(0.0) { }

    void draw() {
        // Gambar badan pesawat
        glColor3f(1.0, 0.0, 0.0); // Warna merah
        glBegin(GL_POLYGON);
        glVertex2f(-0.05, -0.02); // Kiri bawah
        glVertex2f(0.2, -0.02); // Kanan bawah
        glVertex2f(0.3, 0.0);     // Kanan tengah
        glVertex2f(0.2, 0.02);  // Kanan atas
        glVertex2f(-0.05, 0.02);  // Kiri atas
        glEnd();

        // Gambar sayap atas
        glColor3f(0.0, 0.0, 1.0); // Warna biru
        glBegin(GL_POLYGON);
        glVertex2f(0.1, 0.03);  // Kanan atas
        glVertex2f(0.2, 0.03);  // Kiri atas
        glVertex2f(0.1, 0.2);    // Kanan bawah
        glEnd();

        // Gambar sayap bawah
        glColor3f(0.0, 0.0, 1.0); // Warna biru
        glBegin(GL_POLYGON);
        glVertex2f(0.1, -0.03);  // Kanan atas
        glVertex2f(0.2, -0.03);  // Kiri atas
        glVertex2f(0.1, -0.2);    // Kanan bawah
        glEnd();

        // Gambar ekor pesawat
        glColor3f(0.0, 0.0, 1.0); // Warna biru
        glBegin(GL_POLYGON);
        glVertex2f(-0.05, -0.02); // Kiri bawah
        glVertex2f(-0.1, 0.0);     // Kiri tengah
        glVertex2f(-0.05, 0.02);  // Kiri atas
        glEnd();
    }


    void moveLeft() {
        x -= 0.05; // Geser pesawat ke kiri
    }

    void moveDown() {
        y -= 0.05; // Geser pesawat ke bawah
    }

    void moveUp() {
        y += 0.05; // Geser pesawat ke atas
    }

    void moveRight() {
        x += 0.05; // Geser pesawat ke kanan
    }
};

Vehicle vehicle; // Membuat objek kendaraan (mobil)
Rocket rocket; // Membuat objek roket
Plane plane; // Membuat objek pesawat

bool isRocketControlled = false; // Untuk menentukan apakah kontrol roket aktif atau tidak
float rocketY = 0.0; // Untuk menyimpan posisi Y mouse saat mengendalikan roket

void drawCityScene() {
    // Gambar latar belakang pemandangan langit biru muda
    glColor3f(0.6, 0.8, 1.0); // Warna biru muda untuk langit
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, 1.0);   // Titik atas kiri
    glVertex2f(1.0, 1.0);    // Titik atas kanan
    glVertex2f(1.0, -1.0);   // Titik bawah kanan
    glVertex2f(-1.0, -1.0);  // Titik bawah kiri
    glEnd();

    // Gambar matahari
    glColor3f(1.0, 1.0, 0.0); // Warna kuning untuk matahari
    glPushMatrix();
    glTranslatef(-0.7, 0.8, 0.0); // Letakkan matahari di sebelah kiri
    glutSolidSphere(0.2, 20, 20);
    glPopMatrix();

    // Gambar garis putus-putus di jalan dengan warna putih
    glColor3f(1.0, 1.0, 1.0); // Warna putih untuk garis jalan
    glLineWidth(2.0);
    glBegin(GL_LINES);
    for (float i = -1.0; i < 1.0; i += 0.2) {
        glVertex2f(i, -0.75);
        glVertex2f(i + 0.1, -0.75);
    }
    glEnd();
    glLineWidth(1.0);

    // Gambar awan dengan warna putih
    glColor3f(1.0, 1.0, 1.0); // Warna putih untuk awan
    glPushMatrix();
    glTranslatef(0.-0.01, 0.77, 0.0); // Letakkan awan di atas jalan
    glutSolidSphere(0.09, 20, 20);
    glTranslatef(0.1, 0.0, 0.0); // Geser awan ke kanan
    glutSolidSphere(0.09, 20, 20);
    glTranslatef(0.1, 0.0, 0.0); // Geser awan ke kanan lagi
    glutSolidSphere(0.09, 20, 20);
    glPopMatrix();

    // Gambar ke 2 awan dengan warna putih
    glColor3f(1.0, 1.0, 1.0); // Warna putih untuk awan
    glPushMatrix();
    glTranslatef(0.-0.3, 0.50, 0.0); // Letakkan awan di atas jalan
    glutSolidSphere(0.09, 20, 20);
    glTranslatef(0.1, 0.0, 0.0); // Geser awan ke kanan
    glutSolidSphere(0.09, 20, 20);
    glTranslatef(0.1, 0.0, 0.0); // Geser awan ke kanan lagi
    glutSolidSphere(0.09, 20, 20);
    glPopMatrix();

    // Gambar ke 3 awan dengan warna putih
    glColor3f(1.0, 1.0, 1.0); // Warna putih untuk awan
    glPushMatrix();
    glTranslatef(0.4, 0.50, 0.0); // Letakkan awan di atas jalan
    glutSolidSphere(0.09, 20, 20);
    glTranslatef(0.1, 0.0, 0.0); // Geser awan ke kanan
    glutSolidSphere(0.09, 20, 20);
    glTranslatef(0.1, 0.0, 0.0); // Geser awan ke kanan lagi
    glutSolidSphere(0.09, 20, 20);
    glPopMatrix();


    // Ubah warna jalan menjadi abu-abu
    glColor3f(0.5, 0.5, 0.5); // Warna abu-abu untuk jalan
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -0.5);   // Titik atas kiri
    glVertex2f(1.0, -0.5);    // Titik atas kanan
    glVertex2f(1.0, -1.0);   // Titik bawah kanan
    glVertex2f(-1.0, -1.0);  // Titik bawah kiri
    glEnd();

    // Gambar garis putus-putus di jalan dengan warna putih
    glColor3f(1.0, 1.0, 1.0); // Warna putih untuk garis jalan
    glLineWidth(2.0);
    glBegin(GL_LINES);
    for (float i = -1.0; i < 1.0; i += 0.2) {
        glVertex2f(i, -0.75);
        glVertex2f(i + 0.1, -0.75);
    }
    glEnd();
    glLineWidth(1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawCityScene(); // Gambar pemandangan jalan raya, langit, matahari, dan awan
    glTranslatef(vehicle.x, vehicle.y, 0.0); // Terapkan perubahan posisi kendaraan (mobil)
    vehicle.draw(); // Gambar kendaraan (mobil)

    if (isRocketControlled) {
        rocket.y = rocketY; // Geser posisi roket sesuai dengan posisi Y mouse
    }

    glLoadIdentity(); // Kembali ke matriks identitas
    glTranslatef(rocket.x, rocket.y, 0.0); // Terapkan perubahan posisi roket
    rocket.draw(); // Gambar roket

    glLoadIdentity(); // Kembali ke matriks identitas
    glTranslatef(plane.x, plane.y, 0.0); // Terapkan perubahan posisi pesawat
    plane.draw(); // Gambar pesawat

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void specialKey(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_DOWN:
        vehicle.moveDown(); // Geser kendaraan (mobil) ke bawah
        break;
    case GLUT_KEY_UP:
        vehicle.moveUp(); // Geser kendaraan (mobil) ke atas
        break;
    case GLUT_KEY_LEFT:
        vehicle.moveLeft(); // Geser kendaraan (mobil) ke kiri
        break;
    case GLUT_KEY_RIGHT:
        vehicle.moveRight(); // Geser kendaraan (mobil) ke kanan
        break;
    }
    glutPostRedisplay(); // Meminta ulang tampilan untuk menampilkan perubahan
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        plane.moveUp(); // Geser pesawat ke atas
        break;
    case 's':
        plane.moveDown(); // Geser pesawat ke bawah
        break;
    case 'a':
        plane.moveLeft(); // Geser pesawat ke kiri
        break;
    case 'd':
        plane.moveRight(); // Geser pesawat ke kanan
        break;
    }
    glutPostRedisplay(); // Meminta ulang tampilan untuk menampilkan perubahan
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            isRocketControlled = true; // Aktifkan kontrol roket saat tombol kiri mouse ditekan
        }
        else {
            isRocketControlled = false; // Nonaktifkan kontrol roket saat tombol kiri mouse dilepas
        }
    }
}

void motion(int x, int y) {
    if (isRocketControlled) {
        rocketY = (2.0 * y / glutGet(GLUT_WINDOW_HEIGHT)) - 1.0;
        glutPostRedisplay(); // Meminta ulang tampilan untuk menampilkan perubahan
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("City and Vehicles");

    // Set posisi awal objek pesawat di sebelah kiri
    plane.x = -0.6;

    // Set posisi awal objek roket di sebelah kanan
    rocket.x = 0.6;

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKey); // Menghubungkan fungsi specialKey dengan input khusus GLUT
    glutKeyboardFunc(keyboard); // Menghubungkan fungsi keyboard dengan input keyboard
    glutMouseFunc(mouse); // Menghubungkan fungsi mouse untuk kontrol roket
    glutMotionFunc(motion); // Menghubungkan fungsi motion untuk kontrol roket

    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutMainLoop();
    return 0;
}
