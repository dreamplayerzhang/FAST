#ifndef FAST_OPENIGTLINKCLIENT_GUI_HPP_
#define FAST_OPENIGTLINKCLIENT_GUI_HPP_

#include "FAST/Visualization/Window.hpp"

class QPushButton;
class QLineEdit;
class QLabel;
class QElapsedTimer;
class QComboBox;

namespace fast {

class IGTLinkStreamer;
class OpenIGTLinkClient;

class GUI : public Window {
    FAST_OBJECT(GUI)
    public:
        void record();
        void connect();
        void selectStream();
        void updateMessages();
    private:
        GUI();
        void refreshStreams();

        QPushButton* connectButton;
        QLineEdit* mAddress;
        QLineEdit* mPort;
        bool mConnected;
        SharedPointer<IGTLinkStreamer> mStreamer;
        std::vector<std::string> mStreamNames;
        SharedPointer<OpenIGTLinkClient> mClient;

        QLabel* recordingInformation;
        QPushButton* recordButton;
        QElapsedTimer* mRecordTimer;
        QLineEdit* storageDir;
        QComboBox* mSelectStream;

};

} // end namespace fast

#endif
