#ifndef QNITE_ARTIST_H
#define QNITE_ARTIST_H

#include <QQuickItem>

class QniteAxes;
class QniteArtist: public QQuickItem
{
  Q_OBJECT
  Q_PROPERTY(QniteAxes* axes READ axes NOTIFY axesChanged)
  Q_PROPERTY(bool selectable READ selectable WRITE setSelectable NOTIFY selectableChanged)
  Q_PROPERTY(bool selected READ selected NOTIFY selectedChanged)
  Q_PROPERTY(bool propagateSelection READ propagateSelection WRITE setPropagateSelection NOTIFY propagateSelectionChanged)

public:
  explicit QniteArtist(QQuickItem* parent = 0);
  virtual ~QniteArtist();

  QniteAxes* axes() const;
  bool selectable() const { return m_selectable; }
  bool selected() const;
  virtual bool select(QPoint);
  virtual bool select(const QList<QPoint>&);
  bool propagateSelection() const { return m_propagate_selection; }

  void setAxes(QniteAxes* axes);
  void setSelectable(bool selectable);
  virtual void clearSelection() {}
  void setPropagateSelection(bool);

public Q_SLOTS:
  virtual void processData() = 0;

Q_SIGNALS:
  void axesChanged();
  void selectableChanged();
  void selectedChanged();
  void propagateSelectionChanged();

protected:
  virtual void updateAxes();
  virtual bool isSelected() const { return false; }

private:
  QniteAxes* m_axes;
  bool m_selectable;
  bool m_propagate_selection;
};

#endif // QNITE_ARTIST_H

