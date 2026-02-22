# Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O2
TARGET = wordcounter
SOURCES = wordcounter.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Цель по умолчанию
all: $(TARGET)

# Компоновка
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Компиляция
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJECTS) $(TARGET)

# Установка (для deb-пакета)
install: $(TARGET)
	install -d $(DESTDIR)/usr/local/bin
	install -m 755 $(TARGET) $(DESTDIR)/usr/local/bin/

# Проверка наличия компилятора
check-compiler:
	@command -v $(CXX) >/dev/null 2>&1 || { echo "Ошибка: $(CXX) не найден. Установите build-essential."; exit 1; }

.PHONY: all clean install check-compiler