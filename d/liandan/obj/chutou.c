inherit ITEM;
void create()
{
        set_name(HIC"��ͷ"NOR, ({ "chu tou"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�ѳ�ͷ!\n");
                set("unit", "��"); 
                set("no_get",1);
                set("no_drop",1);             
                set("no_put",1);
                set("no_give",1);   
                set("value",100000);
        }
    setup();
}

