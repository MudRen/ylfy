// Room: hantan-hole1.c

inherit ROOM;

void create()
{
        set("short", "�ܶ�");
        set("long", @LONG
һ������Ķ���������·���һ��ǧ�꺮��������������������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hantan",
]));
set("objects", ([
"/kungfu/class/mingjiao/xiexun":1,
]));
        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_tang", "tang");
}
int do_tang(string arg)
{
object obj;
        obj = this_player();
        if( !arg || arg=="" ) return 0;
        if ((int)this_player()->query_skill("force", 1) < 50) {
                message_vision(
"$N�Ļ����ڹ��������޷�����ǧ�꺮����������\n",this_player());
              return 1;
                            }
        if ( (int)this_player()->query("jing") < 30 || (int)this_player()->query("qi") < 60) {
                message_vision(
"$N�Ѿ��ܲ���ǧ�꺮������Ϯ��\n",this_player());
               return 1;
                }
        if( arg=="hanbing" ) {
                if (!query("hs_trigger")){
                message_vision(
"$N����ǧ�꺮�����������棬�����ڹ����Կ�������\n"
".....�����ؽ��������ҵ�״̬....\n", this_player());
       this_player()->add("qi", (-1)*80);
      this_player()->add("jing", (-1)*60);
                this_player()->add("neili", 20);
                this_player()->set_temp("marks/˯", 1);
                return 1;
                }
                message_vision(
"$N���ˣ����ﲻ���ɣ�\n", this_player());
                return 1;
        }
        return 0;
}


