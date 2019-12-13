// ----/d/jianyu.c ----
#include <ansi.h>
inherit ROOM;
nosave string *verbs=({"look","say","help","quit"});
void create()
{
        set("short", "������");
        set("long", @LONG
һ��û�ж��ֵ��ƾ�ľ����Φ���ϰ���һ�������ӣ����滭��һ��
����ͷ����������ˮ�ݵ��е�ù�õ����������س���緫�������ǽ���
�����ﱻ�����Ľ��䣬����ԶҲ��֪�����⴬����Ҫʻ�����
LONG
        );
        set("no_fight",1);
        set("freeze",1);
        set("no_magic",1);
        setup();
}
void init()
{
   object me=this_player();
    if (me->query("id") == "demogorgon"){
     me->move(VOID_OB);
     call_out("dest",1,me);
     return;
    }
    if (!userp(me)) return;
    if (wizardp(me)){
        me->delete("shen");
        add_action("do_summon","summon");
        add_action("kick_out","kickout");
        return;
        }
    me->set("startroom",base_name(this_object()));
    me->set("block",time());
    if(me->is_ghost()) me->reincarnate();
    me->save();
    add_action("discmds","",1);

   remove_call_out("do_rumor");
   call_out("do_rumor",300);
}
int dest(object me)
{
    if (!me) return 0;
            message("vision",me->name()+"����һЦ����������������������ܣ����ˣ��Ϸ�����һ����bye��\n",this_object());
    destruct(me);
    return 1;
}

int discmds(string arg)
{
    string verb=query_verb();
    if( EMOTE_D->do_emote( this_player(), verb, arg ) )
      return 1;
    if (member_array(verb,verbs)==-1)
        tell_object(this_player(),"��Υ������Ϸ����, ��úõķ�ʡһ�����������Ϊ��\n");
    else
        return 0;
    return 1;
}
void do_rumor()
{
    object ob;

   if (!sizeof(ob)) return;
   foreach (ob in all_inventory(this_object()) )
   if (userp(ob) && !wizardp(ob) ) {
        if (time()-ob->query("block")>86400*2){
            ob->delete("block");
            ob->set("startroom","/d/city/wumiao");
            ob->move("/d/city/wumiao");
            message("vison",ob->name()+"�Ӱ���л���һ������Ļ��ߣ��Һ��Ź�����űߣ�\n",environment(ob),({ob}));
            continue;
        }
        CHANNEL_D->do_channel(this_object(),"sys",HIR+ob->name(1)+"�ڴ�����ץ����ѽ��"+NOR);
   }
   tell_room(this_object(),
    "��Զ���Ľ�����Լ�����϶������ĸ�����\n\n"+
"            �׺�һ��Ц��������������\n"+
"            ��������ֻ�ǽ񳯡�\n"+
"            ����Ц���׷����ϳ���\n"+
"            ˭��˭ʤ��֪����\n"+
"            ��ɽЦ������ң��\n"+
"            �����Ծ��������ཿ��\n"+
"            ���Ц�����Ǽ��ȣ�\n"+
"            �������ڳճ�ЦЦ��\n"+
"            ����Ц�����ټ��ȣ�\n"+
"            �������ڳճ�ЦЦ��\n");
    call_out("do_rumor",300);
}

int do_summon(string str)
{
    object me=this_player();
    object ob;
    if (!str || !wizardp(me)) return 0;
    ob = LOGIN_D->find_body(str);
    if (!ob) ob=find_player(str);
    if (!ob|| !me->visible(ob)) return notify_fail("��... ���������?\n");
    if (ob==me) return notify_fail("������... ���ܰ��Լ���������\n");
    if (environment(ob)==environment(me))   return notify_fail(ob->name(1)+"�Ѿ���������ˡ�\n");
    tell_object(ob,"����ǰһ���....,����һ����ţ:����������?\n");
    ob->move(environment(me));
    tell_object(me, "���"+(string)ob->query("name")+"ץ�������ǰ.\n");
    return 1;
}
int kick_out(string str)
{
    object me=this_player();
    object ob;
    if (!str || !wizardp(me)) return 0;
    if (!ob=present(str,this_object()))
        return 0;
    if (!userp(ob))      return 0;
    ob->set("startroom","/d/city/wumiao");
    message_vision("$N������Ű�$n�����������������ҽŰ�$n���˳�ȥ��\n",me,ob);
    ob->move("/d/city/wumiao");
    message("vison",ob->name()+"�Ӱ���л���һ������Ļ��ߣ��Һ��Ź�����űߣ�\n",environment(ob),({ob}));
    return 1;
}

