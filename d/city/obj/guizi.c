// mabudai.c �鲼��
inherit ITEM;
void create()
{
        set_name("���չ�", ({ "baoxian gui", "gui"}));
        set_weight(2100000000);
        set_max_encumbrance(800000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ר��������Ź�����Ʒ�Ĺ��ӡ�\n");
                set("value", 100);
        }
        set("no_clean_up",10000000);
}
int is_container() { return 1; }
void init()
{
	add_action("do_get","get");
	add_action("do_put","put");
}

int do_get(string arg)
{
    string str;
    object me=this_player();
    if (!arg) return 0;
    if (!sscanf(arg,"%s from gui",str))
    if (!sscanf(arg,"%s from baoxian gui",str))
    return 0;
    if ((me->query("id")!="zjkknds")){
    write("��Ҫ������˼ҵĶ�����\n");
    return 1;
    }else
 return 0;
}
int do_put(string arg)
{
    string str;
    object me=this_player();
    if (!arg) return 0;
    if (!sscanf(arg,"%s in gui",str))
    if (!sscanf(arg,"%s in baoxian gui",str))
    return 0;
    if ((me->query("id")!="zjkknds")){
   write("�����������Ͱ��\n");
    return 1;
    }else
 return 0;
}
void reset()  {   }
int query_autoload() { return 1; }