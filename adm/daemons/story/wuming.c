#include <ansi.h>
#include <localtime.h>

#define GOT_MAX_NEILI 100000

int give_gift();

mixed *story = ({
  " ����ɽ��һ��Сɽ�����������",
  "������ͷ���Ǳ�����������ٲ��������������������ڣ���",
  "�����������Ѿ��ѽ������ˣ����������׾����ҵ�������Ⱳ�Ӷ�����õ�����",
  "������ȥ���ɣ�����˵�����ϸֽ��������˴�ȥ�������������˲��ܶ�����ֻ�ñ�Ŀ������",
  "�����������������ֽ������ÿ���ֻ��һ����������֮ǰ��",
  "�����˺ÿ�����֡����������Ǻ��ˣ���",
  " ���������������ߣ�������˭��Ϊ����˶Դ�һ�����ˣ���",
  "���������Ϸ��ͽ�ܡ����ȡ������ȡ�����",
  "��ʲô������ʦ���棬�����๼����������",
  "���ڡ��������������Ѵ��ض�����������",
  "���㡣����������",
  " ������������",
  "����ǰ�����������ˣ���",
  "�������ұ�����ͽ͵Ϯ���������ˣ����»�˶���ˡ���",
  "��ǰ�����Ҹ����˹����ˡ���",
  "�������ˣ��ҵ�������Ȼ�ܵ��ش���������٢Ҳ�Ȳ����ҡ���",
  " ���˰����Ե�ʯ��һš���Աߵ�ʯ��ͻȻ����һ��ʯϻ�����˴�ʯϻ���ó�һ�����顣",
  "�������ɱ�������ͽ��Ҳ�������һ����æ���Ȿ���׾��͸���ɣ�ϣ�����Ժ��ܶ��������塣��",
  "���ҽ��������������Ҿͳ�ȫ�㣬���ҵ�һ������������ɡ���",
  "��ǰ�����ɣ���",
  "���𶯣���",
  "��������������",
  (: give_gift :),
});

string prompt() { return HIG "������������" NOR; }      

void create()
{
    seteuid(getuid());
}



mixed query_story_message(int step)
{
    return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{

    int i;
    object ob;
    object *players;
    string msg;
    object book;
    mixed *tm=localtime(time());

    players = users();
    if (sizeof(players) >= 30)
    {
	for (i = 0; i < 30; i++)
	{
	    ob = players[random(sizeof(players))];
	    if (wizardp(ob)) continue;
	    if (!environment(ob)) continue;
	    if (ob->query_temp("netdead")) continue;
		//if (ob->query("max_neili") > 10000000) continue;
	}
	if(!ob) return 1;

	if (ob)
	{
	    tell_object(ob, HIC "������������ǵõ��������׺����˵ı���������\n" NOR);  
	    message("channel:chat", HIG"������������"+HIW" ��˵" + ob->name(1) + "�����������ǵõ����������׺����˵ı���������\n"NOR,users() );
		if (ob->query("max_neili") < 100000)
		{
	    ob->add("max_neili",GOT_MAX_NEILI * random(10));
		}
		else if (ob->query("max_neili") < 1000000)
		{
	    ob->add("max_neili",GOT_MAX_NEILI + random(GOT_MAX_NEILI));
		}
		else ob->add("max_neili", random(GOT_MAX_NEILI));
	    book = new("/clone/book/wuming");
	   /* if(book && objectp(book))
	    {
		book->move(ob);
		ob->set("qinhuang",1);
	    }*/
	    msg=sprintf("%d-%d-%d %d:%d:%d",tm[LT_YEAR],tm[LT_MON]+1,tm[LT_MDAY],tm[LT_HOUR],tm[LT_MIN]+1,tm[LT_SEC]+1);
	    log_file("story_wuming.log",ob->name(1) + "�����������ǵõ����������׺����˵ı���������["+msg+"]\n");
	}
	STORY_D->remove_story("wuming");
    }
    return 1;
}

