inherit ITEM;

int do_locate(string arg);
int do_task();

void create()
{
        set_name(HIW"̽��"HIG"ͼ"NOR, ({"tanbao tu","tu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long", "����һ������Ѱ�Ҷ�ʧ�����̽��ͼ��\n"+
                            "����(zhao)�����ҵ���Ʒ�Ĵ��λ�ã�\n");
                set("unit", "��");
                set("value", 300);
        }
}

void init()
{
  add_action("do_zhao","zhao");
  add_action("do_task","task");
}

int do_task()
{
   string output;
   output="̽��ͼ��ͻȻӳ�ֳ�һƪӬͷС�֣�\n\n"+"/adm/daemons/questd"->dyn_quest_list();
   this_player()->start_more(output);
   return 1;
}

int query_autoload() { return 1; }

int do_zhao(string arg)
{
   if ( ! arg)

   return notify_fail("zhao <��Ʒ>\n");
   else
   "/adm/daemons/questd"->locate_quest(this_player(),arg);
   return 1;
}
