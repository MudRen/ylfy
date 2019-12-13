// Room: /d/huashan/sgyhole.c

inherit ROOM;

void create()
{
        set("short", "��ڼ�");
        set("long", @LONG
������������ɵ���ڼ��ˣ���ֻ���������ǽ���϶�
����Ų�ͬ��״���ˣ���ʾ�Ų�ͬ���Ṧ����ȭ����ʽ��
LONG );
        set("exits", ([ 
            "west"     : "d/xuantian/xiaolu",
			"north"     : "d/xuantian/mishi",
        ]));
        set("no_clean_up", 0);

        setup();
}
void init()
{
  if (userp(this_player()))
{
  if((string)this_player()->query("family/family_name")!="������")
{
this_player()->move("d/xuantian/xiaolu");
message_vision("$N���������ɵ��ӣ�����ڻ��ǻؼ���ɡ�\n",this_player());
return;
}
}
        add_action("do_mianbi", "mianbi");
        add_action("do_out", "out");
}

int do_mianbi()
{
   object ob;
   int c_skill;
   ob = this_player();

   c_skill=(int)ob->query_skill("literate", 1);
   if (c_skill <1500)
   {
      message_vision("$N������������ǿ����ȫ��������ǽ�ϵ��书��\n",ob);
      return 1; 
   }

   if (ob->query("jing")<2000)
   {
      message_vision("$N̫���ˣ��������ȥֻ��Ҫ�ε���\n",ob);
      return 1; 
   }
     if (ob->query_skill("dodge", 1)>4100)
   {
      message_vision("$N��������Ѿ����ܶ��Լ����书���������ˡ�\n",ob);
      return 1; 
   }

   message_vision(RED"$N��ϥ����,�����ǽ�����书��$N�������Լ����Ṧ��\n"NOR,ob);
   ob->improve_skill("dodge", (int)ob->query_skill("dodge", 1));
  ob->add("jing",-500);
   ob->start_busy(1);
   ob->move("d/xuantian/xiaolu");
   return 1;
}

int do_out(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="����" )
        {
                message("vision",
                        me->name() + "һ�������������˽�ȥ��\n",
                        environment(me), ({me}) );
                me->move("d/xuantian/lyj");
                message("vision",
                        me->name() + "�Ӷ������˽�����\n",
                        environment(me), ({me}) );
                return 1;
        }
}  

