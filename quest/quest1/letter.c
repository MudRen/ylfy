
inherit ITEM;

void create()
{
        set_name("�ż�", ({"xin", "letter"}));
        set("long",
               "�����Ų��и�����ż���\n");
        set("unit", "��");
        set("weight", 5);
//      set("no_drop", 1);
        set("no_get", 1);

        setup();
}
void owner_is_killed() { destruct(this_object()); }

