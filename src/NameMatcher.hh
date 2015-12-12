<?hh //strict

/**
 * This file is part of hhpack\package.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\package;

final class NameMatcher<T as NamedObject> implements Matcher<T>
{

    private string $pattern;

    public function __construct(
        string $pattern
    )
    {
        $this->pattern = '/' . $pattern . '/';
    }

    public function matches(T $item) : bool
    {
        return preg_match($this->pattern, $item->getName()) === 1;
    }

    public static function startsWith(string $keyword) : this
    {
        $pattern = '^' . preg_quote($keyword, '/');
        return new static($pattern);
    }

    public static function endsWith(string $keyword) : this
    {
        $pattern = preg_quote($keyword, '/') . '$';
        return new static($pattern);
    }

}