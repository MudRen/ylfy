#define BOOK   5
#define FILE   "/doc/doc/00"+BOOK
inherit ITEM;
void create()
{
    set_name("(��"+chinese_number(BOOK)+"��) "+BOLD+"��������"+NOR, ({ "book" }));
    set_weight(50);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", CYN "\n                      ��  ��  ��  ��\n______________________________________________________\n"+NOR);
        set("value", 500);
        set("no_sell",1);
        set("material", "silk");
    }
}

string long()
{
      return query("long")+read_file(FILE);
}
int query_autoload() { return 1; }
