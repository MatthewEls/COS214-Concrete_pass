// TableState.h
#pragma once

class TableState {
public:
    virtual void seatTable() = 0;
    virtual void freeTable() = 0;
    virtual bool isAvailable() = 0;
};

class AvailableTableState : public TableState {
public:
    void seatTable() override;
    void freeTable() override;
    bool isAvailable() override;
};

class NotAvailableTableState : public TableState {
public:
    void seatTable() override;
    void freeTable() override;
    bool isAvailable() override;
};
