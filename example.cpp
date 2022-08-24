#include <eosio/eosio.hpp>
#include <eosio/system.hpp>

using namespace eosio;

class [[eosio::contract]] example : public contract {
    public:
    using contract::contract;

    [[eosio::action]]
    void getblock()
    {
        const uint32_t block_num = eosio::current_block_number();
        getblocklog_action getblocklog( get_self(), { get_self(), "active"_n });
        getblocklog.send(block_num);
    }

    [[eosio::action]]
    void getblocklog( const uint32_t block_num ) {
        print(block_num);
    }

    using getblock_action = action_wrapper<"getblock"_n, &example::getblock>;
    using getblocklog_action = action_wrapper<"getblocklog"_n, &example::getblocklog>;
};
