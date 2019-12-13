// vote unjail
// bbb 99.1.25
#include <vote.h> 
#include <ansi.h>
#define V_UNJAIL 30

inherit F_CONDITION;

int clear_vote(object me);

int vote(object me, object victim)
{
  int reason; // vote for what?
  int vv;	// valid voter numbers
  int vc; 	// vote count;
  int df;
  string *juror, my_id;

  if (me == victim)
  {
	if (random(2)) me->add("vote/abuse", 10);
  	return notify_fail("�㲻�ǿ���Ц�ɣ����ı�������Ȩ��\n");
  }


//   if( victim->query("unjail_on") ) 	
if( !victim->query("block") ) 	
  {
  	return notify_fail(victim->name()+"���ڲ��ڼ�����\n");
  }

  if (reason <= 0)
  {
  	victim->set("vote/reason", (int)V_UNJAIL); 
  }
  
  my_id = me->query("id");

  // dont allow me to vote twice for the same issue
  juror = victim->query("vote/juror");
  
  if( !pointerp(juror) )
  {
 	victim->set("vote/juror", ({ my_id }) );
  } else if( member_array(my_id, juror) == -1 ) 
  {
 	victim->set("vote/juror", juror+({ my_id }) );
  } else
  {
	me->add("vote/abuse", 10);
  	return notify_fail("һ��һƱ�����ñ��Ȩ��Ҫ�ܳͷ��ģ�\n");
  }

//    vv = (int) ("/cmds/std/vote")->valid_voters(me)/6;  	
vv = (int) ("/cmds/std/vote")->valid_voters(me)/2;  	
  vc = victim->add("vote/count", 1);

  df = vv - vc;
  if (vv < 4) df = 4 - vc;

  if (df>0)
  { 
        shout( HIG "�������"+me->name(1)+"ͶƱ��"+victim->name(1)+"("+capitalize(victim->query("id"))+")"
			+"�Ӽ����ͷţ�����"+chinese_number(df)+"Ʊ��\n" NOR);
	write( HIG "�������"+me->name(1)+"ͶƱ��" +victim->name(1)
			+"�Ӽ����ͷţ�����"+chinese_number(df)+"Ʊ��\n" NOR);
	victim->apply_condition("vote_clear", 10);
  } else 
  {
        shout( HIG "�������"+me->name(1)+"ͶƱ��" +victim->name(1)+"("+capitalize(victim->query("id"))+")"
			+"�Ӽ����ͷš�"+victim->name(1)+"���ͷ��ˣ�\n" NOR);
	write( HIG "�������"+me->name()+"ͶƱ��" +victim->name()
			+"�Ӽ����ͷš�"+victim->name(1)+"���ͷ��ˣ�\n" NOR);
			
	victim->apply_condition("vote_clear", -10);
//     victim->set("unjail_on", 1);	
victim->delete("block",);	
	victim->move("/d/city/wumiao.c");
  } 
  
  return 1;
}
