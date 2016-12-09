CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		EstudosOpenCv.o, ScanImg_LookupTbl_TimeMeasure.o, LoadImage.o, Threshold.o

CFLAGS = `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv`

TARGET =	EstudosOpenCv, ScanImg_LookupTbl_TimeMeasure, LoadImage, Threshold

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
