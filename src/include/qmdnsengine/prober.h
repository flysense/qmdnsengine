/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef QMDNSENGINE_PROBER_H
#define QMDNSENGINE_PROBER_H

#include <QObject>

#include "qmdnsengine_export.h"

namespace QMdnsEngine
{

class Record;
class Server;

class QMDNSENGINE_EXPORT ProberPrivate;

/**
 * @brief Propose a record before using it to confirm its uniqueness
 */
class QMDNSENGINE_EXPORT Prober : public QObject
{
    Q_OBJECT

public:

    Prober(Server *server, const Record &record, QObject *parent = 0);

Q_SIGNALS:

    /**
     * @brief Indicate that the name has been confirmed unique
     * @param name that was confirmed to be unique
     */
    void nameConfirmed(const QByteArray &name);

private:

    ProberPrivate *const d;
};

}

#endif // QMDNSENGINE_PROBER_H
