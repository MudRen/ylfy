inherit ROOM;
#include <ansi.h>
string look_notice();
void create()
{
        set("short", "���ƺ");
    set("long", @LONG
����ǰ��һƬ��ɫ�Ĵ��ƺ,��ƺ��������һ���ʯ̨��ʯ̨���Ա߷�����
һ��ʯ��(notice)��һ��Сľ��(paizi)��ʯ���ĺ���һ�����(flag)ӭ����չ!!!!!!!
LONG
    );
        set("item_desc", ([ /* sizeof() == 1 */
  "���" : "����һֻţƤ�Ƴɵľ޹ģ�������ʿ�ڻ�ɽ�۽�ʱ����(knock)����ʼ���䡣",
  "flag" : " �� �� Ӣ �� �� �� �� ",
      "notice" : (: look_notice :),
]));
    set("exits", ([ /* sizeof() == 2 */
    "south":__DIR__"houzhiwangyu",
        ]));
    set("no_fight",1);
    set("objects",([
       "/clone/misc/drum1":1,
    ]));
    setup();
}
void init()
{
       object me=this_player();
       int age=(int)me->query("mud_age") / 86400 + 14;
       if (!wizardp(me) && ( age >= 18 || age < 14) ){
            tell_object(me,"������ָ����㣺�㲻������������ر��䣡��ѡ����������Ӧ�ĳ��أ���\n");
            me->move(__DIR__"houzhiwangyu");
            return;
       }

       add_action("discmds",({"study","respitate","exert","array","duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","scribe","surrender","sha"}));
//       if (userp(me) && me->query("no_get") )
         if ( me->query("no_get") )
           call_out("do_recover",1,me);
}
void do_recover(object me)
{
    if( !me || environment(me) != this_object() ) return;
       me->delete("no_get");
       if (!living(me)) me->revive();
    me->set("eff_jing",me->query("max_jing"));
    me->set("jing",me->query("max_jing"));
    me->set("eff_qi",me->query("max_qi"));
        me->set("qi",me->query("max_qi"));
    if (me->query("neili")<me->query("max_neili"))
        me->set("neili",me->query("max_neili"));
    if (me->query("jingli")<me->query("max_jingli"))
        me->set("jingli",me->query("max_jingli"));
       me->clear_condition();
    me->set("food",me->max_food_capacity());
    me->set("water",me->max_water_capacity());
    me->start_busy(0);
}
int discmds()
{
        tell_object(this_player(),"�����㻹��ר�Ŀ�����ɣ�\n");

     return 1;
}
string look_notice()
{
        object who;
        string *name_list, file;
        int i, j=0, k;
        who=this_player();
        file=read_file("/log/fight/lunjian1");
        if(!file)
                return "Ŀǰû���κα����¼��\n";
        name_list = explode(file,"\n");
        for(i=0;i<sizeof(name_list);i++) {
                if(name_list[i] == "seperator" ) {
                        j++;
                        k=0;
                        printf("\n��"+chinese_number(j)+"��(������)��ɽ�۽������\n");
                        continue;
                }
                k++;
                printf(GRN "��"+chinese_number(k)+"����%-50s\n" NOR, name_list[i]);
        }
        return "\n";
}

