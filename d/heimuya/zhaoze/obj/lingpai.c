// lingpai.c
inherit ITEM;
void create()
{
        set_name(BLU "��������" NOR, ({"ling pai", "ling"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", 
                "    "+YEL+"����һ��"+NOR+""+BLU+"����"+NOR+""+YEL+",�������һȺ����������ƺ�֮�ϡ��������\n"
                "�硢�ơ��ס����ĸ�׭�ֺ�һ��ѷ��䡣"+NOR+"\n");
        set("unit", "��");
        set("weight", 10);
        set("no_drop","��ô�ѵõĶ�������ö�����");
        set("no_sell",1);
        set("no_put",1);
        set("material", "iron");
        }
        setup();
        call_out("dest", 3600);
}
void dest()
{
    object ob=environment(this_object());
    if (ob)
    if (userp(ob)){
            tell_object(ob, HIY "ͻȻ���д���һ�����������㻳������ƺ��Ļ���һֻ��ɫ��\n"+"���񣬷�����в����ˣ�\n" NOR);
            message("vision",
                HIY "��������һ����������һ��������һ����\n"
                "ֻ��һֻ��ɫ�����������У�һ�¾Ͳ����ˣ�\n" NOR, environment(ob), ob);
    }
    destruct(this_object());
}

int query_autoload() { return 1; }