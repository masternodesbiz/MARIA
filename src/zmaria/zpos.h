// Copyright (c) 2020 The MARIA developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MARIA_LEGACY_ZPOS_H
#define MARIA_LEGACY_ZPOS_H

#include "stakeinput.h"
#include "txdb.h"

class CLegacyZMariaStake : public CStakeInput
{
private:
    uint32_t nChecksum{0};
    libzerocoin::CoinDenomination denom{libzerocoin::ZQ_ERROR};
    uint256 hashSerial{UINT256_ZERO};

public:
    CLegacyZMariaStake(const CBlockIndex* _pindexFrom, uint32_t _nChecksum, libzerocoin::CoinDenomination _denom, const uint256& _hashSerial) :
        CStakeInput(_pindexFrom),
        nChecksum(_nChecksum),
        denom(_denom),
        hashSerial(_hashSerial)
    {}

    static CLegacyZMariaStake* NewZMariaStake(const CTxIn& txin, int nHeight);

    bool IsZMARIA() const override { return true; }
    uint32_t GetChecksum() const { return nChecksum; }
    const CBlockIndex* GetIndexFrom() const override;
    CAmount GetValue() const override;
    CDataStream GetUniqueness() const override;
    bool GetTxOutFrom(CTxOut& out) const override { return false; /* not available */ }
};

#endif //MARIA_LEGACY_ZPOS_H
